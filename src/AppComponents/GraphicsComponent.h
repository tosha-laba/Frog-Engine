#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "../Utils/INativeImage.h"
#include "../Utils/Color.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    // Нужно состояние для цвета и ширины
    // нужны операции push/pop?
    class INativeImage;

    /*!
        \brief Интерфейс графической компоненты приложения
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
        \see INativeImage

        Интерфейс, обеспечивающий независимый от реализации
        набор методов для рисования изображений и графических
        примитивов на экране.

        При написании своей реализации компонент приложения,
        следует реализовать этот интерфейс в отдельном классе.
     */
    class GraphicsComponent
    {
    public:
        GraphicsComponent();
        virtual ~GraphicsComponent();

        /// Режимы отрисовки примитивов
        enum DrawMode {
            Fill,   ///< Заполнение - закрашивает область примитива
            Stroke  ///< Контур - рисует границу примиитва
        };

        //! Очищает область экрана
        virtual void clear() = 0;

        /*!
         * \brief Рисует эллипс заданных размеров в заданной точке
         * \param mode Режим отрисовки
         * \param x Координата X
         * \param y Координата Y
         * \param w Ширина эллипса
         * \param h Высота эллипса
         */
        virtual void drawEllipse(DrawMode mode, int x, int y, int w, int h) = 0;

        /*!
         * \brief Рисует прямоугольник заданных размеров в заданной точке
         * \param mode Режим отрисовки
         * \param x Координата X
         * \param y Координата Y
         * \param w Ширина эллипса
         * \param h Высота эллипса
         */
        virtual void drawQuad(DrawMode mode, int x, int y, int w, int h) = 0;

        /*!
         * \brief Рисует линию из (x1,y1) в (x2,y2)
         * \param x1 Координата X начала линии
         * \param y1 Координата Y начала линии
         * \param x2 Координата X конца линии
         * \param y2 Координата Y конца линии
         */
        virtual void drawLine(int x1, int y1, int x2, int y2) = 0;

        /*!
         * \brief Рисует текст в заданной точке
         * \param text Отображаемый текст
         * \param x Координата X
         * \param y Координата Y
         */
        virtual void drawText(const char *text, int x, int y) = 0;

        /*!
         * \brief Отображает изображение в заданной точке
         * \param image Изображение
         * \param x Координата X
         * \param y Координата Y
         */
        virtual void drawImage(INativeImage *image, int x, int y) = 0;

        /*!
         * \brief Отображает изображение заданных размеров в заданной точке
         * \param image Изображение
         * \param x Координата X
         * \param y Координата Y
         * \param w Ширина изображения
         * \param h Высота изображения
         */
        virtual void drawImage(INativeImage *image, int x, int y, int w, int h) = 0;

        /*!
         * \brief Отображает часть изображения из заданной области в заданной точке
         * \param image Изображение
         * \param x Координата X
         * \param y Координата Y
         * \param sx Координата X исходной области
         * \param sy Координата Y исходной области
         * \param sw Ширина области
         * \param sh Высота области
         */
        virtual void drawImage(INativeImage *image, int x, int y, int sx, int sy, int sw, int sh) = 0;

        /*!
         * \brief Устанавливает цвет отрисовки
         * \param color Цвет
         * \see Color
         */
        virtual void setColor(Color color) = 0;
    };

}

/*! @} End of Doxygen Groups*/

#endif // GRAPHICSCOMPONENT_H
