#ifndef QT_NATIVE_SOUND_H
#define QT_NATIVE_SOUND_H

#include "../Utils/INativeSound.h"
#include <QSoundEffect>

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog
{
    /*!
        \brief Реализация звукового объекта для платформы Qt
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
     */
    class QtNativeSound : public INativeSound
    {
    public:
        QtNativeSound(const char *source);
        virtual ~QtNativeSound() {}

        virtual void play(float volume = 1, bool loop = false);
        virtual void setVolume(float volume = 1);
        virtual void stop();

    private:
        QSoundEffect effect;
    };

} // Frog

/*! @} End of Doxygen Groups*/

#endif // QT_NATIVE_SOUND_H
