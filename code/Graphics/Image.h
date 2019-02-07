#ifndef IMAGE_H
#define IMAGE_H

#include "../Graphic.h"
#include "../Utils/INativeImage.h"
#include "../FG.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    //! Графический объект - обертка над изображением платформы
    class Image : public Graphic
    {
    public:
        Image() {}
        Image(INativeImage *image) : image(image) {}
        virtual ~Image() {}

    protected:
        virtual void render(int x, int y) {
            if (image != nullptr && FG::graphics != nullptr)
                FG::graphics->drawImage(image, x, y);
        }

    private:
        INativeImage *image = nullptr;
    };

}

/*! @} End of Doxygen Groups*/

#endif // IMAGE_H
