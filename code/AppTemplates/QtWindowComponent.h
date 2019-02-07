#ifndef QT_WINDOW_COMPONENT_H
#define QT_WINDOW_COMPONENT_H

#include "../FG.h"
#include <QOpenGLWindow>
#include <QKeyEvent>
#include <QMouseEvent>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация оконной компоненты для платформы Qt
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
     */
    class QtWindowComponent : public WindowComponent, public QOpenGLWindow
    {
    public:
        QtWindowComponent() : WindowComponent(), QOpenGLWindow() { QOpenGLWindow::startTimer(5); }
        //! Создает объект, связывает с движком, начинает обновление кадров
        QtWindowComponent(Engine *engine) : WindowComponent(engine), QOpenGLWindow() { QOpenGLWindow::startTimer(5); }
        virtual ~QtWindowComponent() {}

        virtual void closeWindow();

        virtual void setWidth(int width);
        virtual void setHeight(int height);

        virtual int getWidth();
        virtual int getHeight();

        virtual void setTitle(const char* title);
        virtual void setFullscreen(bool isFullscreen = true);

    protected:
        //! Перегрузка события показа окна Qt
        void showEvent(QShowEvent *event);
        //! Перегрузка события действия по таймеру Qt
        void timerEvent(QTimerEvent *event);
        //! Перегрузка события нажатия на клавишу клавиатуры Qt
        void keyPressEvent(QKeyEvent *event);
        //! Перегрузка события отпускания клавиши клавиатуры Qt
        void keyReleaseEvent(QKeyEvent *event);
        //! Перегрузка события движения мыши Qt
        void mouseMoveEvent(QMouseEvent *event);
        //! Перегрузка события нажатия кнопок мыши Qt
        void mousePressEvent(QMouseEvent *event);
        //! Перегрузка события отпускания кнопок мыши Qt
        void mouseReleaseEvent(QMouseEvent *event);
        //! Перегрузка события отрисовки при помощи OpenGL
        void paintGL();

        virtual void update();
        virtual void draw();

        virtual void keyPressed(int keyCode);
        virtual void keyReleased(int keyCode);

        virtual void mouseMoved(int x, int y);
        virtual void mousePressed(int x, int y, int button);
        virtual void mouseReleased(int x, int y, int button);

    };
} // Frog

/*! @} End of Doxygen Groups*/

#endif // QT_WINDOW_COMPONENT_H
