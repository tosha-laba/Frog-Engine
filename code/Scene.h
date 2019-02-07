#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <memory>
#include <algorithm>
#include "Entity.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class Engine;

    /*!
        \brief Сцена - основной класс реализации игровой логики
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
        \see Entity

        Класс, экземпляры которого при связи с движком
        (если в качестве сцены установлен конкретный экземпляр)
        могут исполнять логику, связанную с инициалиацией ресурсов,
        обновлением, отрисовкой экрана, взаимодействием с мышью
        и клавиатурой.

        На сцену могут добавляться сущности, которые будут обновляться
        и отрисовываться.
        Имея адрес сущности, можно удалить сущность из текущего набора.

        Ваша игра должна наследовать сцены от данного класса.
     */
    class Scene
    {
    public:
        Scene();
        virtual ~Scene();

        void addEntity(Entity *entity);
        void removeEntity(Entity *entity);

        virtual void init();
        virtual void update();
        virtual void onDraw();

        virtual void keyPressed(int keyCode);
        virtual void keyReleased(int keyCode);

        virtual void mouseMoved(int x, int y);
        virtual void mousePressed(int x, int y, int button);
        virtual void mouseReleased(int x, int y, int button);

    protected:
        bool isPressed(int key);

    private:
        //! Список с отслеживаемыми адресами сущностей
        std::list< std::shared_ptr<Entity> > entities;
    };

}

/*! @} End of Doxygen Groups*/

#endif // SCENE_H
