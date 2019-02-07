#ifndef GRAPHIC_H
#define GRAPHIC_H

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class Entity;

    /*!
        \brief Интерфейс графического объекта
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
        \see Entity, INativeImage

        Устанавливает договоренность, что графические объекты
        должны каким-то образом отображаться, если задана точка (x,y)

        Графические объекты игры должны реализовывать этот интерфейс.
     */
    class Graphic
    {
    public:
        Graphic();

        /*!
         * \brief Метод отображения графического объекта в точке (x,y)
         * \param x Координата X
         * \param y Координата Y
         */
        virtual void render(int x, int y) = 0;
    };

}

/*! @} End of Doxygen Groups*/

#endif // GRAPHIC_H
