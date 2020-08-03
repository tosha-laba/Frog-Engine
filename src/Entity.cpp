#include "Entity.h"

namespace Frog {
    /*!
     * \brief Пустой конструктор
     *
     * Создает объект без графического содержимого в точке (0,0)
     */
    Entity::Entity()
    {

    }

    /*!
     * \brief Конструктор
     * \param x Координата X
     * \param y Координата Y
     */
    Entity::Entity(int x, int y)
        : x(x), y(y)
    {

    }

    /*!
     * \brief Конструктор
     * \param graphic Графическое содержимое сущности
     * \param x Координата X
     * \param y Координата Y
     */
    Entity::Entity(Graphic *graphic, int x, int y)
        : x(x), y(y), graphic(graphic)
    {

    }

    Entity::~Entity()
    {

    }

    /*!
     * \brief Выполняет логику при обновлении кадра.
     */
    void Entity::update()
    {

    }

    /*!
     * \brief Отрисовывает графический объект в позиции (x,y)
     */
    void Entity::render()
    {
        if (graphic != nullptr)
            graphic->render(x, y);
    }

    /*!
     * \brief Устанавливает графическое содержимое
     * \param graphic Графическое содержимое
     */
    void Entity::setGraphic(Graphic *graphic)
    {
        this->graphic = graphic;
    }

    /*!
     * \brief Устанавливает позицию сущности
     * \param x Координата X
     * \param y Координата Y
     */
    void Entity::setPos(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    /*!
     * \brief Устанавливает компоненту координаты X
     * \param x Позиция сущности по оси OX
     */
    void Entity::setX(int x)
    {
        this->x = x;
    }

    /*!
     * \brief Устанавливает компоненту координаты Y
     * \param y Позиция сущности по оси OY
     */
    void Entity::setY(int y)
    {
        this->y = y;
    }

    /*!
     * \brief Получает компоненту координаты X
     * \return Позиция сущности по OX
     */
    int Entity::getX()
    {
        return x;
    }

    /*!
     * \brief Получает компоненту координаты Y
     * \return Позиция сущности по OY
     */
    int Entity::getY()
    {
        return y;
    }

}
