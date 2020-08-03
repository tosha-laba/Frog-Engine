#ifndef ENGINE_H
#define ENGINE_H

#include "Scene.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class WindowComponent;
    class QtWindowComponent;

    /*!
        \brief Описывает часть логики игры и предоставляет управление сценами.
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019
        \see App

        Класс, экземпляры которого при связи с приложением могут исполнять
        логику, связанную с инициалиацией ресурсов, обновлением, отрисовкой экрана,
        взаимодействием с мышью и клавиатурой, а также проделывать аналогичные действия
        со сценами, менять текущую сцену игры.

        Ваша игра, если необходим доступ к игровой логике на данном этапе,
        должна содержать класс, наследуемый от данного и перегружающий его функции.
     */
    class Engine
    {
    public:
        Engine();
        Engine(Scene *scene);

        void setScene(Scene *scene);

    protected:
        virtual void init();
        virtual void update();
        virtual void onRender();

        virtual void keyPressed(int keyCode);
        virtual void keyReleased(int keyCode);

        virtual void mouseMoved(int x, int y);
        virtual void mousePressed(int x, int y, int button);
        virtual void mouseReleased(int x, int y, int button);

    private:
        friend class WindowComponent;
        friend class QtWindowComponent;

        //! Адрес текущей сцены движка
        Scene *scene = nullptr;
    };

}

/*! @} End of Doxygen Groups*/


#endif // ENGINE_H
