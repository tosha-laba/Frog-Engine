#include "LogoScene.h"
#include "MenuScene.h"
#include "../FG.h"
#include <cmath>

LogoScene::LogoScene()
{
    Frog::FG::audio->createSound("croak.wav")->play();
}

void LogoScene::update()
{
    if (isLogo) {
        opacityParameter += 0.01;
        if (opacityParameter > M_PI) {
            isLogo = false;
        } else {
            logo.setAlpha(sinf(opacityParameter));
        }
    } else {
        davidLynchTimer += 0.005;

        if (davidLynchTimer > M_PI) {
            Frog::FG::engine->setScene(new MenuScene());
            delete this;
        }
    }
}

void LogoScene::onDraw()
{
    Scene::onDraw();

    if (isLogo) {
        Frog::FG::graphics->drawImage(&logo, 200, 100, 400, 400);
    } else {
        Frog::FG::graphics->setColor(Frog::Color(255, 255, 255, 255 * atanf(davidLynchTimer / 2.)));
        Frog::FG::graphics->drawText("A Hideo Kojima game", 350, 300);
    }
}
