#ifndef QT_NATIVE_IMAGE_H
#define QT_NATIVE_IMAGE_H

#include "../Utils/INativeImage.h"
#include "QtGraphicsComponent.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация графического изображения для платформы Qt
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
     */
    class QtNativeImage : public INativeImage
    {
    public:
        QtNativeImage() {}
        QtNativeImage(const char *fileName) : pixmap(fileName) {}

        void nativeDraw(int x, int y) {
            ((QtGraphicsComponent*)FG::graphics)->drawPixmap(pixmap, x, y, alpha);
        }

        void nativeDraw(int x, int y, int w, int h) {
            ((QtGraphicsComponent*)FG::graphics)->drawPixmap(pixmap, x, y, w, h, alpha);
        }

        void nativeDraw(int x, int y, int sx, int sy, int sw, int sh) {
            ((QtGraphicsComponent*)FG::graphics)->drawPixmap(pixmap, x, y, sx, sy, sw, sh, alpha);
        }

        int getWidth() { return pixmap.width(); }
        int getHeight() { return pixmap.height(); }

        void setAlpha(float alpha) { this->alpha = alpha; }
        float getAlpha() { return alpha; }

    private:
        QPixmap pixmap;
        float alpha = 1;
    };
} // Frog

/*! @} End of Doxygen Groups*/

#endif // QT_NATIVE_IMAGE_H
