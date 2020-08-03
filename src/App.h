#ifndef APP_H
#define APP_H

#include "AppComponents/AudioComponent.h"
#include "AppComponents/WindowComponent.h"
#include "AppComponents/GraphicsComponent.h"
#include "Engine.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    /*!
        \brief Класс приложения, собирающий в себя его компоненты.
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019

        Собирает в одно место и связывает компоненты приложения, предоставляет
        доступ к ним. Обеспечивает точку входа в приложение.

        Реализация компонент для определенной платформы может включать
        класс, наследуемый от данного.
     */
    class App
    {
    public:
        App();

        App(WindowComponent *window,
            AudioComponent *audio,
            GraphicsComponent *graphics,
            Engine *engine);

        App(const char *title,
            int width,
            int height,
            WindowComponent *window,
            AudioComponent *audio,
            GraphicsComponent *graphics,
            Engine *engine);

        virtual ~App();

        //! Закрывает приложение
        void close() { window->closeWindow(); }

        /*!
         * \brief Устанавливает заголовок окна
         * \param title Текст заголовка
         */
        void setTitle(const char *title) { window->setTitle(title); }
        /*!
         * \brief Устанавливает ширину окна
         * \param width Ширина
         */
        void setWidth(int width) { window->setWidth(width); }
        /*!
         * \brief Устанавливает высоту окна
         * \param height Высота
         */
        void setHeight(int height) { window->setHeight(height); }
        //! Получает текущую ширину окна
        int getWidth() { return window->getWidth(); }
        //! Получает текущую высоту окна
        int getHeight() { return window->getHeight(); }

    protected:
        //! Хранимый адрес оконного компонента приложения
        WindowComponent *window = nullptr;
        //! Хранимый адрес аудио-компонента приложения
        AudioComponent *audio = nullptr;
        //! Хранимый адрес графического компонента приложения
        GraphicsComponent *graphics = nullptr;
        //! Хранимый адрес объекта движка
        Engine *engine = nullptr;

    };

}

/*! @} End of Doxygen Groups*/

#endif // APP_H
