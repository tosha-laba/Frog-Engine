#include "App.h"
#include "FG.h"

namespace Frog {
    App::App()
    {

    }

    /*!
     * \brief Конструктор
     * \details Принимает на вход указатели на компоненты и объект движка,
     *          связывает движок с окном.
     * \param window Конкретный оконный компонент
     * \param audio Конкретный компонент звуковой системы
     * \param graphics Конкретный компонент графической системы
     * \param engine Конкретный объект движка с игровой логикой
     */
    App::App(WindowComponent *window, AudioComponent *audio, GraphicsComponent *graphics, Engine *engine)
        : window(window), audio(audio), graphics(graphics), engine(engine)
    {
        FG::window = window;
        FG::graphics = graphics;
        FG::audio = audio;
        FG::engine = engine;
        FG::app = this;

        window->setEngine(engine);
    }

    /*!
     * \brief Конструктор c параметрами окна
     * \details Вызывает конструктор и устанавливает заголовок и размер окна.
     * \param title Заголовок окна
     * \param width Ширина окна
     * \param height Высота окна
     * \param window Конкретный оконный компонент
     * \param audio Конкретный компонент звуковой системы
     * \param graphics Конкретный компонент графической системы
     * \param engine Конкретный объект движка с игровой логикой
     */
    App::App(const char *title,
             int width,
             int height,
             WindowComponent *window,
             AudioComponent *audio,
             GraphicsComponent *graphics,
             Engine *engine)
        : App::App(window, audio, graphics, engine)
    {
        window->setTitle(title);
        window->setWidth(width);
        window->setHeight(height);
    }

    App::~App()
    {

    }

}

