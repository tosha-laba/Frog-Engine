#ifndef WINDOWCOMPONENT_H
#define WINDOWCOMPONENT_H

#include "../Engine.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    /*!
        \brief Абстрактный класс оконной компоненты приложения
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019

        Обеспечивает платформо-независимое управление состоянием
        окна, связывает события конкретной реализации с методами
        движка, сцены и сущностей.

        Реализация компонент для определенной платформы может включать
        класс, наследуемый от данного.
     */
    class WindowComponent
    {
    public:
        WindowComponent();
        WindowComponent(Engine *engine);
        virtual ~WindowComponent();

        void setEngine(Engine *engine);

        //! Закрывает окно
        virtual void closeWindow() = 0;

        /*!
         * \brief Устанавливает ширину окна
         * \param width Ширина
         */
        virtual void setWidth(int width) = 0;

        /*!
         * \brief Устанавливает высоту окна
         * \param height Высота
         */
        virtual void setHeight(int height) = 0;
        virtual void setSize(int width, int height);

        //! Получает ширину окна
        virtual int getWidth() = 0;
        //! Получает высоту окна
        virtual int getHeight() = 0;

        //!
        //! \brief Устанавливает заголовок окна
        //! \param title Текст заголовка
        //!
        virtual void setTitle(const char* title) = 0;
        //!
        //! \brief Меняет отображение окна с обычного на полноэкранное и наоборот
        //! \param isFullscreen true - переводит в полноэкранный, false - переводит в оконный режим
        //!
        virtual void setFullscreen(bool isFullscreen = true) = 0;

    protected:
        //! Вызывается при обновлении кадра окна
        virtual void update() = 0;
        //! Вызывается при отрисовке кадра окна
        virtual void draw() = 0;

        //! Вызывается при нажатии на клавишу с заданным кодом
        virtual void keyPressed(int keyCode) = 0;
        //! Вызывается при отпускании клавиши с заданным кодом
        virtual void keyReleased(int keyCode) = 0;

        //! Вызывается при перемещении мыши в точку (x,y)
        virtual void mouseMoved(int x, int y) = 0;
        //! Вызывается при нажатии кнопки мыши в точке (x,y)
        virtual void mousePressed(int x, int y, int button) = 0;
        //! Вызывается при отпускании кнопки мыши в точке (x,y)
        virtual void mouseReleased(int x, int y, int button) = 0;


        Engine* engine = nullptr;
    };

}

/*! @} End of Doxygen Groups*/

#endif // WINDOWCOMPONENT_H
