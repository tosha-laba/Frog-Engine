#ifndef NATIVEIMAGE_H
#define NATIVEIMAGE_H

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    /*!
        \brief Интерфейс графического изображения платформы
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019

        Интерфейс, который должны реализовывать конкретные
        платформо-зависимые классы отображаемых изображений.

        При написании своей реализации компонент приложения,
        следует реализовать этот интерфейс в отдельном классе.
    */
    class INativeImage
    {
      public:
        ~INativeImage() {}

        /*!
         * \brief Отображает изображение в точке (x, y)
         * \param x Координата X
         * \param y Координата Y
         */
        virtual void nativeDraw(int x, int y) = 0;

        /*!
         * \brief Отображает изображение в точке (x, y) шириной w, высотой h
         * \param x Координата X
         * \param y Координата Y
         * \param w Ширина отображаемого изображения
         * \param h Высота отображаемого изображения
         */
        virtual void nativeDraw(int x, int y, int w, int h) = 0;

        /*!
         * \brief Отображает в точке (x,y) часть изображения,
         * \brief взятого из прямоугольной области (sx, sy, sw, sh)
         * \param x Координата X
         * \param y Координата Y
         * \param sx Координата X оригинального изображения
         * \param sy Координата Y оригинального изображения
         * \param sw Ширина области
         * \param sh Высота области
         */
        virtual void nativeDraw(int x, int y, int sx, int sy, int sw, int sh) = 0;

        //! Получает ширину изображения
        virtual int getWidth() = 0;
        //! Получает высоту изображения
        virtual int getHeight() = 0;

        /*!
         * \brief Устанавливает альфа-канал изображения
         * \param alpha Значение альфа-канала (0 <= alpha <= 1)
         */
        virtual void setAlpha(float alpha) = 0;
        //! Получает значение альфа-канала
        virtual float getAlpha() = 0;
    };

}

/*! @} End of Doxygen Groups*/

#endif // NATIVEIMAGE_H
