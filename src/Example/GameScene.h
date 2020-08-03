#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene.h"
#include "../FG.h"
#include "Tilemap.h"
#include "../AppTemplates/QtNativeImage.h"
#include "Player.h"

/*!
 * \brief Главная игровая сцена
 *
 * Содержит сущности героя, карты и коробки.
 *
 * Управляет движением героя, столкновениями с картой и коробкой.
 * Отрисовывает дополнительные элементы, вроде сообщений или показателя здоровья.
 */
class GameScene : public Frog::Scene
{
public:
    GameScene();
    virtual ~GameScene();

protected:
    void update();
    void onDraw();
    void keyPressed(int keyCode);
    void keyReleased(int keyCode);

private:
    char *tiles;
    Tileset *set;
    //! Тайловая карта уровня
    Tilemap *map;

    int heroLifes = 6;

    Frog::QtNativeImage healthImage = Frog::QtNativeImage("heart.png");

    Frog::INativeSound *music;
    Frog::INativeSound *deathMusic;
    Frog::INativeSound *victoryMusic;

    //! Герой
    Player *player;

    //! Коробка
    Box *box;

    bool canJump = true;
    bool notDead = true;
    bool isVictory = false;

    float deathTimer = 0;
    float victoryTimer = 0;

    int cameraPosX = 0;
};

#endif // GAMESCENE_H
