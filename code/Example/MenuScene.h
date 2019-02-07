#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../Scene.h"
#include "../AppTemplates/QtNativeImage.h"

#define JOKE

//! Графический объект "кнопки" (текст в горизонтальной рамке)
class ButtonGraphic : public Frog::Graphic
{
public:
    ButtonGraphic(std::string text, int width, int height) : width(width), height(height), text(text) {}

    void render(int x, int y) {
        Frog::FG::graphics->setColor(Frog::Color(100, 100, 100));
        Frog::FG::graphics->drawQuad(Frog::GraphicsComponent::DrawMode::Fill, x, y, width, height);
        Frog::FG::graphics->setColor(Frog::Color(175, 175, 175));
        Frog::FG::graphics->drawText(text.c_str(), x + 20, x + 25);
    }

private:
    int width;
    int height;

    std::string text;
};

//! Сущность "кнопки"
class Button : public Frog::Entity
{
public:
    Button(std::string text, int x, int y, int width, int height)
        : Entity(x, y)
    {
        setGraphic(new ButtonGraphic(text, width, height));
    }
};

/*!
    \brief Графический объект текста

     Обертка над методами графической компоненты
*/
class TextGraphic : public Frog::Graphic
{
public:
    TextGraphic(std::string text, Frog::Color color) : text(text), color(color) {}

    void render(int x, int y) {
        Frog::FG::graphics->setColor(color);
        Frog::FG::graphics->drawText(text.c_str(), x, y);
    }

private:
    std::string text;
    Frog::Color color;
};

//! Сущность текста
class Text : public Frog::Entity
{
public:
    Text(std::string text, int x, int y, Frog::Color color = Frog::Color(255, 255, 255))
        : Entity(x, y)
    {
        setGraphic(new TextGraphic(text, color));
    }
};

/*!
    \brief Сцена меню

    Отображает изображение и несколько графических сущностей
*/
class MenuScene : public Frog::Scene
{
public:
    MenuScene();

protected:
    void keyPressed(int keyCode);
    void update();
    void onDraw();

private:
    void menuAction(int linePos);

#ifdef JOKE
    Frog::QtNativeImage menu = Frog::QtNativeImage("menu_trve.png");
#else
    Frog::QtNativeImage menu = Frog::QtNativeImage("menu.png");
#endif

    Button *button;
    Text *carriage;
    Text *runningLine;

    float runningLineX = 0;

    int carriagePos = 0;
};

#endif // MENUSCENE_H
