#include "Engine.h"
#include "FG.h"

namespace Frog {
    Engine::Engine()
    {

    }

    /*!
     * \brief Конструктор
     * \param scene Сцена движка
     */
    Engine::Engine(Scene *scene)
        : scene(scene)
    {

    }

    /*!
     * \brief Устанавливает текущую сцену
     * \param scene Сцена движка
     */
    void Engine::setScene(Scene *scene)
    {
        this->scene = scene;
    }

    /*!
     * \brief Содержит логику, выполняемую при связи движка и приложения.
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::init()
    {
        if (scene != nullptr)
            scene->init();
    }

    /*!
     * \brief Содержит логику, выполняемую при обновлении кадра.
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::update()
    {
        if (scene != nullptr)
            scene->update();
    }

    /*!
     * \brief Содержит логику, выполняемую при отрисовке кадра.
     *
     * Очищает экран и делегирует то же событие сцене, если она есть.
     */
    void Engine::onRender()
    {
        if (FG::graphics != nullptr)
            FG::graphics->clear();

        if (scene != nullptr)
            scene->onDraw();
    }

    /*!
     * \brief Содержит логику, выполняемую при нажатии на клавишу клавиатуры.
     * \param keyCode Код нажатой клавиши.
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::keyPressed(int keyCode)
    {
        if (scene != nullptr)
            scene->keyPressed(keyCode);
    }

    /*!
     * \brief Содержит логику, выполняемую при отпускании клавиши клавиатуры.
     * \param keyCode Код отпущенной клавиши.
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::keyReleased(int keyCode)
    {
        if (scene != nullptr)
            scene->keyReleased(keyCode);
    }

    /*!
     * \brief Содержит логику, выполняемую при перемещении мыши по экрану.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::mouseMoved(int x, int y)
    {
        if (scene != nullptr)
            scene->mouseMoved(x, y);
    }

    /*!
     * \brief Содержит логику, выполняемую при нажатии на кнопку мыши.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     * \param button Код кнопки мыши: 0 - левая, 1 - колесо, 2 - правая
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::mousePressed(int x, int y, int button)
    {
        if (scene != nullptr)
            scene->mousePressed(x, y, button);
    }

    /*!
     * \brief Содержит логику, выполняемую при отпускании кнопки мыши.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     * \param button Код кнопки мыши: 0 - левая, 1 - колесо, 2 - правая
     *
     * Делегирует то же событие сцене, если она есть.
     */
    void Engine::mouseReleased(int x, int y, int button)
    {
        if (scene != nullptr)
            scene->mouseReleased(x, y, button);
    }

}

