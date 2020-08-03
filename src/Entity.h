#ifndef ENTITY_H
#define ENTITY_H

#include "Graphic.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class Scene;

    /*!
        \brief Сущность - игровой объект, хранимый сценой
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
        \see Scene

        Хранит позицию на экране, графический объект,
        отрисовывает графический объект в конкретном месте.

        Позволяет выполнять свою игровую логику при обновлении кадра.

        Игра должна наследовать данный класс для создания своих сущностей.
     */
    class Entity
    {
    public:
        Entity();
        Entity(int x, int y);
        Entity(Graphic *graphic, int x, int y);
        virtual ~Entity();

        virtual void update();
        void render();

        void setGraphic(Graphic *graphic);
        void setPos(int x, int y);

        void setX(int x);
        void setY(int y);

        int getX();
        int getY();

    protected:
        //! Компонента координаты X
        int x = 0;
        //! Компонента координаты Y
        int y = 0;

    private:
        //! Адрес графического содержимого
        Graphic *graphic = nullptr;
    };

}

/*! @} End of Doxygen Groups*/

#endif // ENTITY_H
