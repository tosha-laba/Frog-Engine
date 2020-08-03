#ifndef FG_H
#define FG_H

#include "AppComponents/GraphicsComponent.h"
#include "AppComponents/AudioComponent.h"
#include "Engine.h"
#include "App.h"

#include <map>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class App;
    class GraphicsComponent;
    class AudioComponent;
    class Engine;

    /*!
     * \brief Статический класс для доступа к глобальным свойствам и функциям
     */
    class FG
    {
    private:
        FG();
    public:

        static void setCamera(int x, int y);

        //! Адрес текущего приложения
        static App *app;
        //! Адрес оконной компоненты приложения
        static WindowComponent *window;
        //! Адрес графической компоненты приложения
        static GraphicsComponent *graphics;
        //! Адрес аудио-компоненты приложения
        static AudioComponent *audio;
        //! Адрес объекта движка приложения
        static Engine *engine;

        //! Смещение координат по X для эмуляции камеры
        static int cameraOffsetX;
        //! Смещение координат по Y для эмуляции камеры
        static int cameraOffsetY;

        //! Ассоциативный массив, хранящий состояние нажатия клавиш.
        //! Вернет true, если клавиша с кодом key нажата, false - иначе.
        static std::map<int, bool> keyState;
    };

}

/*! @} End of Doxygen Groups*/

#endif // FG_H
