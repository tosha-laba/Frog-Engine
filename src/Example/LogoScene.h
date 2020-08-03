#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include "../Scene.h"
#include "../AppTemplates/QtNativeImage.h"

/*!
 * \brief Сцена, показывающая логотип движка
 *
 * Показывает логотип движка, меняя прозрачность
 * по синусу с течением времени.
 *
 * Проигрывает звук "кваканья".
 */
class LogoScene : public Frog::Scene
{
public:
    LogoScene();

protected:
    void update();
    void onDraw();

private:
    Frog::QtNativeImage logo = Frog::QtNativeImage("logo.png");
    float opacityParameter = 0;
    float davidLynchTimer = 0;
    bool isLogo = true;
};

#endif // LOGOSCENE_H
