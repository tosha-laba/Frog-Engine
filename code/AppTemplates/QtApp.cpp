#include "QtApp.h"

namespace Frog {
    /*!
     * \brief Создает приложение Qt, связывая с заданным движком и устанавливая параметры окна
     * \param title Заголовок окна
     * \param w Ширина окна
     * \param h Высота окна
     * \param engine Движок
     * \return Адрес созданного приложения
     */
    QtApp *QtApp::createApp(const char *title, int w, int h, Engine *engine)
    {
        return new QtApp(title, w, h, engine);
    }

    QtApp::~QtApp()
    {
        delete qWindow;
        delete qGraphics;
        delete qAudio;
    }

    /*!
     * \brief Запускает приложение в оконном или полноэкранном режиме
     * \param fullscreen true - запускает в полноэкранном режиме, false - в оконном
     */
    void QtApp::run(bool fullscreen)
    {
        qWindow->show();
        if (fullscreen)
            qWindow->showFullScreen();
    }

    QtApp::QtApp()
    {

    }

    /*!
     * \brief Конструктор
     * \param title Текст заголовка
     * \param w Ширина окна
     * \param h Высота окна
     * \param engine Движок
     *
     * С закрытым доступом.
     *
     * Создает компоненты и связывает с движком.
     * Устанавливает параметры окна.
     */
    QtApp::QtApp(const char *title, int w, int h, Engine *engine)
    {
        qWindow = new QtWindowComponent(engine);
        qGraphics = new QtGraphicsComponent(qWindow);
        qAudio = new QtAudioComponent();

        App(title, w, h, qWindow, qAudio, qGraphics, engine);
    }

}
