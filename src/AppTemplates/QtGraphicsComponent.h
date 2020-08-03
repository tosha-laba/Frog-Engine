#ifndef QT_GRAPHICS_COMPONENT_H
#define QT_GRAPHICS_COMPONENT_H

#include "../FG.h"
#include "QtWindowComponent.h"
#include <QPainter>
#include <QPixmap>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация графической компоненты для платформы Qt
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
     */
    class QtGraphicsComponent : public GraphicsComponent
    {
    public:
        QtGraphicsComponent() {}
        QtGraphicsComponent(QtWindowComponent *renderDevice) : renderDevice(renderDevice) {}
        virtual ~QtGraphicsComponent() {}

        void setRenderDevice(QtWindowComponent *renderDevice);

        virtual void clear();

        virtual void drawEllipse(DrawMode mode, int x, int y, int w, int h);
        virtual void drawQuad(DrawMode mode, int x, int y, int w, int h);
        virtual void drawLine(int x1, int y1, int x2, int y2);
        virtual void drawText(const char *text, int x, int y);
        virtual void drawImage(INativeImage *image, int x, int y);
        virtual void drawImage(INativeImage *image, int x, int y, int w, int h);
        virtual void drawImage(INativeImage *image, int x, int y, int sx, int sy, int sw, int sh);

        void drawPixmap(QPixmap &pixmap, int x, int y, float alpha);
        void drawPixmap(QPixmap &pixmap, int x, int y, int w, int h, float alpha);
        void drawPixmap(QPixmap &pixmap, int x, int y, int sx, int sy, int sw, int sh, float alpha);

        virtual void setColor(Color color);

    private:
        QtWindowComponent *renderDevice = nullptr;
        QColor color = QColor(Qt::white);
    };
} // Frog

/*! @} End of Doxygen Groups*/

#endif // QT_GRAPHICS_COMPONENT_H
