#ifndef INATIVESOUND_H
#define INATIVESOUND_H

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    /*!
        \brief Интерфейс звукового объекта платформы
        \author Антон Завьялов 
        \version 1.0
        \date Январь 2019

        Интерфейс, который должны реализовывать конкретные
        платформо-зависимые классы проигрываемых звуков.

        При написании своей реализации компонент приложения,
        следует реализовать этот интерфейс в отдельном классе.
    */
    class INativeSound
    {
      public:
        ~INativeSound() {}

        /*!
         * \brief Проиграть звук
         * \param volume Громкость проигрывания (0 <= volume <= 1)
         * \param loop Будет ли звук зациклен
         */
        virtual void play(float volume = 1, bool loop = false) = 0;

        /*!
         * \brief Установить громкость проигрывания
         * \param volume Громкость проигрывания (0 <= volume <= 1)
         */
        virtual void setVolume(float volume = 1) = 0;

        /*!
         * \brief Остановить воспроизведение
         */
        virtual void stop() = 0;

        /*!
         * \brief Зациклить звук и начать воспроизведение
         * \param volume Громкость проигрывания (0 <= volume <= 1)
         */
        void loop(float volume = 1) {
            play(volume, true);
        }
    };

}

/*! @} End of Doxygen Groups*/

#endif // INATIVESOUND_H
