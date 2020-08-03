#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity.h"
#include "../AppTemplates/QtNativeImage.h"
#include "Spritemap.h"
#include "../FG.h"
#include "../Graphics/Image.h"

//! Коробка - сущность с привязанным графическим объектом
class Box : public Frog::Entity
{
public:
    Box() {
        setGraphic(new Frog::Image(new Frog::QtNativeImage("box.png")));
    }

    Box(int x, int y) : Box() {
        setPos(x, y);
    }
};

/*!
 * \brief Игрок - сущность с анимированным графическим объектом,
 * имеющая логику движения по горизонтали/вертикали,
 * смены анимации при смене состояния некоторого автомата
 */
class Player : public Frog::Entity
{
public:
    Player();
    Player(int x, int y, int lifes);

    void update();

    int getLifes();
    void setLifes(int value);
    void increaseLifes(int value);

    int getBufferX();
    int getBufferY();

    void jump();

    void verticalMovementStart();
    void verticalMovementEnd(bool isColliding);

    void horizontalMovementStart();
    void horizontalMovementEnd(bool isColliding);

private:
    bool isPressed(int keyCode);

    //! Звук прыжка
    Frog::INativeSound *jumpSound = nullptr;

    Frog::QtNativeImage sheet = Frog::QtNativeImage("soldier.png");
    //! Карта кадров героя
    Spritemap *spritemap;

    //! Количество жизней героя
    int lifes = 6;

    //! Количество прыжков героя
    int jumps = 2;

    //! Координатный буффер X
    float _x = 0;
    //! Координатный буффер Y
    float _y = 0;

    //! Вертикальная скорость
    float verticalVelocity = 0;
    //! Горизонтальная скорость
    float horizontalVelocity = 0;

    //! Ускорение по горизонтали
    const float ACCEL_HORIZ = 0.05;
    //! Ускорение по вертикали
    const float ACCEL_VERT = 0.079;
    //! Максимальное горизонтальное ускорение
    const float MAX_HORIZ_VELOCITY = 4;
};

#endif // PLAYER_H
