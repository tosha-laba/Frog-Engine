#include "Spritemap.h"
#include "FG.h"

Spritemap::Spritemap()
{

}

/*!
 * \brief Связывает изображение с объектом, устанавливает размеры кадра и вычисляет количество кадров
 * \param image Изображение
 * \param frameWidth Ширина кадра
 * \param frameHeight Длина кадра
 */
Spritemap::Spritemap(Frog::INativeImage *image, int frameWidth, int frameHeight)
    : image(image), frameWidth(frameWidth), frameHeight(frameHeight)
{
    framesCount = image->getWidth() / frameWidth;
}

//! Создает объект и устанавливает продолжительность анимации
Spritemap::Spritemap(Frog::INativeImage *image, int frameWidth, int frameHeight, float duration)
    : Spritemap(image, frameWidth, frameHeight)
{
    this->duration = duration;
}

//! Отрисовывает текущий кадр
void Spritemap::render(int x, int y)
{
    Frog::FG::graphics->drawImage(image, x, y,
                                  frameWidth * frameIndex,
                                  frameHeight * filmIndex,
                                  frameWidth, frameHeight);
}

//! Устанавливает продолжительность анимации
void Spritemap::setDuration(float value)
{
    duration = value;
}

/*!
 * \brief Начинает проигрывание анимации
 * \param fromStart true - начинает с самого первого кадра, false - с текущего
 */
void Spritemap::play(bool fromStart)
{
    isPlaying = true;

    if (fromStart) {
        frameIndex = 0;
    }
}

/*!
 * \brief Проигрывает зацикленную анимацию
 * \param fromStart ture - начинает с самого первого кадра, false - с текущего
 */
void Spritemap::loop(bool fromStart)
{
    isLoop = true;

    play(fromStart);
}

//! Ставит анимацию на паузу
void Spritemap::pause()
{
    isPlaying = false;
}

//! Останавливает анимацию (на самый первый кадр)
void Spritemap::stop()
{
    isPlaying = false;

    frameIndex = 0;
}

/*!
 * \brief Устанавливает индекс кадра
 * \param index Индекс
 */
void Spritemap::setFrameIndex(int index)
{
    frameIndex = index;
}

/*!
 * \brief Устанавливает индекс плёнки
 * \param index Индекс
 */
void Spritemap::setFilmIndex(int index)
{
    filmIndex = index;
}

/*!
 * \brief Обновляет анимацию
 * Требуется вызывать в методах обновления сцены\сущности\движка
 */
void Spritemap::update()
{
    if (!isPlaying)
        return;

    durationCounter += DURATION_STEP;

    if (durationCounter >= duration) {
        durationCounter = 0;

        if (frameIndex + 1 >= framesCount) {
            if (isLoop) {
                frameIndex = 0;
            } else {
                isPlaying = false;
            }
        } else {
            frameIndex++;
        }
    }
}
