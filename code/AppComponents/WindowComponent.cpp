#include "WindowComponent.h"

namespace Frog {
    WindowComponent::WindowComponent()
    {

    }

    /*!
     * \brief Конструктор
     * \param engine Адрес объекта движка
     *
     * Создает объект и устанавливает связь с движком
     */
    WindowComponent::WindowComponent(Engine *engine)
        : engine(engine)
    {
    }

    WindowComponent::~WindowComponent()
    {

    }

    /*!
     * \brief Устанавливает связь с объектом движка
     * \param engine Движок
     */
    void WindowComponent::setEngine(Engine *engine)
    {
        if (this->engine == nullptr)
            this->engine = engine;
    }

    /*!
     * \brief Устанавливает размер окна
     * \param width Ширина окна
     * \param height Высота окна
     */
    void WindowComponent::setSize(int width, int height)
    {
        setWidth(width);
        setHeight(height);
    }
}
