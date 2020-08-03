#ifndef PLATFORMERENGINE_H
#define PLATFORMERENGINE_H

#include "../Engine.h"

/*!
    \brief Движок игры-примера

    Запускает первую сцену
 */
class PlatformerEngine : public Frog::Engine
{
public:
    PlatformerEngine();

    void init();
};

#endif // PLATFORMERENGINE_H
