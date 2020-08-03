#include "MenuScene.h"
#include "GameScene.h"

//! Заполняет сцену
MenuScene::MenuScene()
{
#ifdef JOKE
    button = new Button("Minecraft 2", 100, 100, 100, 40);
#else
    button = new Button("Platformer", 100, 100, 100, 40);
#endif
    addEntity(button);

    addEntity(new Text("New Game", 120, 180));
    addEntity(new Text("Exit", 140, 210));

    carriage = new Text(">", 100, 180);
    addEntity(carriage);

    runningLine = new Text("By Anton Zavyalov and Nikolay Cheremnov", 0, 590);
    addEntity(runningLine);
}

void MenuScene::keyPressed(int keyCode)
{
    if (keyCode == Qt::Key_Up) {
        if (carriagePos > 0) {
            carriagePos--;
            carriage->setY(180 + 30 * carriagePos);
        }
    } else if (keyCode == Qt::Key_Down) {
        if (carriagePos < 1) {
            carriagePos++;
            carriage->setY(180 + 30 * carriagePos);
        }
    } else if (keyCode == Qt::Key_Z) {
        menuAction(carriagePos);
    }
}

void MenuScene::update()
{
    runningLineX += 0.8;
    if (runningLineX > 800)
        runningLineX = -240;

    runningLine->setX(runningLineX);


}

void MenuScene::menuAction(int linePos)
{
    if (linePos == 0) {
        Frog::FG::engine->setScene(new GameScene());
        delete this;
    } else if (linePos == 1) {
        Frog::FG::window->closeWindow();
    }
}

void MenuScene::onDraw()
{
    Frog::FG::graphics->setColor(Frog::Color(114, 201, 207));
    Frog::FG::graphics->drawQuad(Frog::GraphicsComponent::DrawMode::Fill, 0, 0, 805, 605);

#ifdef JOKE
    Frog::FG::graphics->drawImage(&menu, 0, 0);
#else
    Frog::FG::graphics->drawImage(&menu, -10, 120);
#endif

    Scene::onDraw();
}
