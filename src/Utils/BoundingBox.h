#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    //! Утилитный класс, содержащий функцию проверки на столкновение
    class BoundingBox
    {
    public:
        /*!
        * \brief Проверяет, пересекаются ли два прямоугольника с заданными координатами и размерами
        * \param x1 Координата X первого прямоугольника
        * \param y1 Координата Y первого прямоугольника
        * \param w1 Ширина первого прямоугольника
        * \param h1 Высота первого прямоугольника
        * \param x2 Координата X второго прямоугольника
        * \param y2 Координата Y второго прямоугольника
        * \param w2 Ширина второго прямоугольника
        * \param h2 Высота второго прямоугольника
        * \return true - если прямоугольники пересекаются, false - иначе
        */
       static bool checkCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
           return   x1 < x2 + w2 &&
                    x2 < x1 + w1 &&
                    y1 < y2 + h2 &&
                    y2 < y1 + h1;
       }
    };

}

/*! @} End of Doxygen Groups*/

#endif // BOUNDING_BOX_H
