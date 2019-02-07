#ifndef QT_APP_H
#define QT_APP_H

#include "../App.h"
#include "../FG.h"
#include "QtWindowComponent.h"
#include "QtGraphicsComponent.h"
#include "QtAudioComponent.h"
#include <QOpenGLWindow>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSoundEffect>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация класса приложения для платформы Qt
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
     */
    class QtApp : public App
    {
    public:
        static QtApp *createApp(const char *title, int w, int h, Engine *engine);
        virtual ~QtApp();

        void run(bool fullscreen = false);

    private:
        QtApp();
        QtApp(const char *title, int w, int h, Engine *engine);

        QtWindowComponent *qWindow;
        QtGraphicsComponent *qGraphics;
        QtAudioComponent *qAudio;
    };
}

/*! @} End of Doxygen Groups*/

#endif // QT_APP_H
