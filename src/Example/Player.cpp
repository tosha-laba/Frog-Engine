#include "Player.h"
#include <cmath>

//! Добавляет графический объект,
//! звуковой объект звука прыжка
Player::Player()
{
    spritemap = new Spritemap(&sheet, 64, 64);
    setGraphic(spritemap);

    spritemap->setFilmIndex(2);
    spritemap->setDuration(0.5);
    spritemap->loop(true);

    jumpSound = Frog::FG::audio->createSound("jump.wav");
}

//! Устанавливает позицию и количество "жизней"
Player::Player(int x, int y, int lifes)
    : Player()
{
    setPos(x, y);

    this->_x = x;
    this->_y = y;
    this->lifes = lifes;
}

//! Логика обновления персонажа
void Player::update()
{
    if (horizontalVelocity > 0.8) {
        spritemap->setFilmIndex(2);
        spritemap->play(false);
    } else if (horizontalVelocity < -0.8) {
        spritemap->setFilmIndex(3);
        spritemap->play(false);
    } else if (horizontalVelocity > -0.8 && horizontalVelocity < 0.8) {
        spritemap->setFilmIndex(0);
        spritemap->play(false);
    } if (horizontalVelocity == 0) {
        spritemap->pause();
    }

    spritemap->update();

    if (y > 800 && lifes > 0) {
        verticalVelocity = -10;
        horizontalVelocity = 0;
        lifes = 0;
    }

}

//! Получает количество "жизней" героя
int Player::getLifes()
{
    return lifes;
}

//! Устанавливает количество "жизней"
void Player::setLifes(int value)
{
    lifes = value;
}

//! Увеличивает количество жизней на некоторое (может быть и отрицательное) значение
void Player::increaseLifes(int value)
{
    lifes += value;
}

//! Получает координатный буффер по X
int Player::getBufferX()
{
    return (int)_x;
}

//! Получает координатный буффер по Y
int Player::getBufferY()
{
    return (int)_y;
}


//! Герой совершает прыжок, если количество оставшихся прыжков положительное
//! Количество прыжков уменьшается на 1
void Player::jump()
{
    if (jumps > 0) {
        verticalVelocity = -(7 + jumps) / 2.;
        jumps--;

        if (jumpSound != nullptr)
            jumpSound->play();
    }
}

//! Начало движения по вертикали
//! Записывает координаты, вычисленные методом Эйлера в буффер
void Player::verticalMovementStart()
{
    verticalVelocity += ACCEL_VERT;
    _y = y + verticalVelocity;
}

//! Завершает движение по вертикали
//! В зависимости от того, было или нет столкновение,
//! выбирается, какая координата пойдет на отображение:
//! если было - то выходная,
//! если не было - буфферная
void Player::verticalMovementEnd(bool isColliding)
{
    if (!isColliding) {
        setY(_y);
    } else {
        if (verticalVelocity > 0)
            jumps = 2;

        verticalVelocity = 0;
    }
}

//! Начало движения по горизонтали
//! Если нажаты клавиши <- или ->, дать приращение скорости в том или ином направлении
//! Выбрать минимальную по модулю скорость
void Player::horizontalMovementStart()
{
    if (isPressed(Qt::Key_Left))
        horizontalVelocity -= ACCEL_HORIZ;
    else if (isPressed(Qt::Key_Right))
        horizontalVelocity += ACCEL_HORIZ;

    horizontalVelocity = horizontalVelocity > 0
            ? fminf(horizontalVelocity, MAX_HORIZ_VELOCITY)
            : fmaxf(-MAX_HORIZ_VELOCITY, horizontalVelocity);

    _x = x + horizontalVelocity;
}

//! Завершает движение по горизонтали
//! В зависимости от того, было или нет столкновение,
//! выбирается, какая координата пойдет на отображение:
//! если было - то выходная,
//! если не было - буфферная
void Player::horizontalMovementEnd(bool isColliding)
{
    if (!isColliding)
        setX(_x);
    else
        horizontalVelocity = 0;

    if (!isPressed(Qt::Key_Left) && !isPressed(Qt::Key_Right)) {
        if (horizontalVelocity > 0)
            horizontalVelocity -= 0.04;
        else
            horizontalVelocity += 0.04;

        if (fabsf(horizontalVelocity) < 0.05)
            horizontalVelocity = 0;
    }

}

//! Проверяет по коду, нажата ли та или иная кнопка клавиатуры
bool Player::isPressed(int keyCode)
{
    auto it = Frog::FG::keyState.find(keyCode);

    if (it != Frog::FG::keyState.end()) {
        return it->second;
    }

    return false;
}
