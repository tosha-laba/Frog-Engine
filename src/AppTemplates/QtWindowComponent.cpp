#include "QtWindowComponent.h"
#include "FG.h"

namespace Frog
{
    void QtWindowComponent::closeWindow()
    {
        QOpenGLWindow::close();
    }

void QtWindowComponent::setWidth(int width)
    {
        QOpenGLWindow::setWidth(width);
        QOpenGLWindow::setMaximumWidth(width);
    }

    void QtWindowComponent::setHeight(int height)
    {
        QOpenGLWindow::setHeight(height);
        QOpenGLWindow::setMaximumHeight(height);
    }

    int QtWindowComponent::getWidth()
    {
        return QOpenGLWindow::size().width();
    }

    int QtWindowComponent::getHeight()
    {
        return QOpenGLWindow::size().height();
    }

    void QtWindowComponent::setTitle(const char *title)
    {
        QOpenGLWindow::setTitle(title);
    }

    void QtWindowComponent::setFullscreen(bool isFullscreen)
    {
        if (isFullscreen)
            QOpenGLWindow::showFullScreen();
        else
            QOpenGLWindow::showNormal();
    }

    void QtWindowComponent::showEvent(QShowEvent *event)
    {
        if (engine != nullptr)
            engine->init();
    }

    void QtWindowComponent::timerEvent(QTimerEvent *event)
    {
        this->update();
        QOpenGLWindow::update();
    }

    void QtWindowComponent::keyPressEvent(QKeyEvent *event)
    {
        FG::keyState[event->key()] = true;
        keyPressed(event->key());
    }

    void QtWindowComponent::keyReleaseEvent(QKeyEvent *event)
    {
        FG::keyState[event->key()] = false;
        keyReleased(event->key());
    }

    void QtWindowComponent::mouseMoveEvent(QMouseEvent *event)
    {
        mouseMoved(event->x(), event->y());
    }

    void QtWindowComponent::mousePressEvent(QMouseEvent *event)
    {
        int button;

        if (event->button() == Qt::LeftButton) {
            button = 0;
        } else if (event->button() == Qt::RightButton) {
            button = 1;
        } else if (event->button() == Qt::MidButton) {
            button = 2;
        } else {
            return;
        }

        mousePressed(event->x(), event->y(), button);
    }

    void QtWindowComponent::mouseReleaseEvent(QMouseEvent *event)
    {
        int button;

        if (event->button() == Qt::LeftButton) {
            button = 0;
        } else if (event->button() == Qt::RightButton) {
            button = 1;
        } else if (event->button() == Qt::MidButton) {
            button = 2;
        } else {
            return;
        }

        mouseReleased(event->x(), event->y(), button);
    }

    void QtWindowComponent::paintGL()
    {
        draw();
    }

    void QtWindowComponent::update()
    {
        engine->update();
    }

    void QtWindowComponent::draw()
    {
        engine->onRender();
    }

    void QtWindowComponent::keyPressed(int keyCode)
    {
        engine->keyPressed(keyCode);
    }

    void QtWindowComponent::keyReleased(int keyCode)
    {
        engine->keyReleased(keyCode);
    }

    void QtWindowComponent::mouseMoved(int x, int y)
    {
        engine->mouseMoved(x, y);
    }

    void QtWindowComponent::mousePressed(int x, int y, int button)
    {
        engine->mousePressed(x, y, button);
    }

    void QtWindowComponent::mouseReleased(int x, int y, int button)
    {
        engine->mouseReleased(x, y, button);
    }
} // Frog
