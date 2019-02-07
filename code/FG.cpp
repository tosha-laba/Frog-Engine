#include "FG.h"

namespace Frog {
    App *FG::app = nullptr;
    WindowComponent *FG::window = nullptr;
    GraphicsComponent *FG::graphics = nullptr;
    AudioComponent *FG::audio = nullptr;
    Engine *FG::engine = nullptr;

    int FG::cameraOffsetX = 0;
    int FG::cameraOffsetY = 0;

    std::map<int, bool> FG::keyState;

    FG::FG()
    {

    }

    /*!
     * \brief Устанавливает позицию камеры на экране
     * \param x Координата X
     * \param y Координата Y
     */
    void FG::setCamera(int x, int y)
    {
        FG::cameraOffsetX = x;
        FG::cameraOffsetY = y;
    }

}
