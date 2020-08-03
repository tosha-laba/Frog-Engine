#ifndef SPRITEMAP_H
#define SPRITEMAP_H

#include "../Graphic.h"
#include "../Utils/INativeImage.h"

/*!
 * \brief Покадровый графический объект с возможностью проигрывания анимаций
 *
 * Здесь "плёнка" - проигрываемая покадровая анимация
 */
class Spritemap : public Frog::Graphic
{
public:
    Spritemap();
    Spritemap(Frog::INativeImage *image, int frameWidth, int frameHeight);
    Spritemap(Frog::INativeImage *image, int frameWidth, int frameHeight, float duration);
    virtual ~Spritemap() {}

    void render(int x, int y);

    void setDuration(float value);

    void play(bool fromStart = true);
    void loop(bool fromStart = false);
    void pause();
    void stop();

    void setFrameIndex(int index);
    void setFilmIndex(int index);

    void update();
private:
    //! Изображение с кадрами
    Frog::INativeImage *image = nullptr;

    //! Ширина кадра
    int frameWidth;
    //! Длина кадра
    int frameHeight;

    //! Количество кадров в "плёнке"
    int framesCount;

    //! Продолжительность анимации
    float duration = 1;

    //! Индекс текущего кадра
    int frameIndex = 0;
    //! Индекс текущей "плёнки"
    int filmIndex = 0;

    bool isPlaying = false;
    bool isLoop = false;

    float durationCounter = 0;

    const float DURATION_STEP = 0.03;
};

#endif // SPRITEMAP_H
