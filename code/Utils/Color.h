#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    //! Независимое от реализации приложения представление цвета в формате ARGB
    class Color
    {
    public:
        /*!
         * \brief Конструктор
         * \param r Интенсивность красного (0 <= r < 256)
         * \param g Интенсивность зеленого (0 <= g < 256)
         * \param b Интенсивность синего (0 <= b < 256)
         * \param alpha Величина альфа-канала (0 <= a < 256)
         */
        Color(int r, int g, int b, int alpha = 255) {
            representation |= (0x000000ff & r) << 16;
            representation |= (0x000000ff & g) << 8;
            representation |= (0x000000ff & b);
            representation |= (0x000000ff & alpha) << 24;
        }

        /*!
         * \brief Получает четырехбайтовое представление цвета
         * \return Четырехбайтвое число в порядке Big-Endian, где:
         * \return 1 бит - величина альфа-канала
         * \return 2 бит - величина канала красного
         * \return 3 бит - величина канала зеленого
         * \return 4 бит - величина канала синего
         */
        std::uint32_t getRepresentation() { return representation; }

    private:
        std::uint32_t representation = 0x00000000;

    };

}

/*! @} End of Doxygen Groups*/

#endif // COLOR_H
