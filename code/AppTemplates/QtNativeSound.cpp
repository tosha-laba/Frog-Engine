#include "QtNativeSound.h"

namespace Frog
{
    QtNativeSound::QtNativeSound(const char *source)
    {
        effect.setSource(QUrl::fromLocalFile(source));
    }

    void QtNativeSound::play(float volume, bool loop)
    {
        setVolume(volume);

        effect.setLoopCount(loop ? QSoundEffect::Infinite : 1);

        effect.play();
    }

    void QtNativeSound::setVolume(float volume)
    {
        effect.setVolume(volume);
    }

    void QtNativeSound::stop()
    {
        effect.stop();
    }
} // Frog