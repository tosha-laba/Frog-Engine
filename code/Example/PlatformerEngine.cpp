#include "PlatformerEngine.h"
#include "LogoScene.h"

PlatformerEngine::PlatformerEngine()
{

}

//! Создает сцену с логотипом
void PlatformerEngine::init()
{
    setScene(new LogoScene());
}
