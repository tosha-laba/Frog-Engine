#ifndef QT_AUDIO_COMPONENT_H
#define QT_AUDIO_COMPONENT_H

#include "../AppComponents/AudioComponent.h"
#include "QtNativeSound.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация аудио-компоненты для платформы Qt
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
     */
    class QtAudioComponent : public AudioComponent
    {
    public:
        virtual ~QtAudioComponent() {}

        virtual INativeSound *createSound(const char *source) {
            return new QtNativeSound(source);
        }
    };
} // Frog

/*! @} End of Doxygen Groups*/

#endif // QT_AUDIO_COMPONENT_H
