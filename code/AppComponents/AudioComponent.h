#ifndef AUDIOCOMPONENT_H
#define AUDIOCOMPONENT_H

#include "../Utils/INativeSound.h"

/*!
 *  \addtogroup Frog
 *  @{
 */

//! Пространство имен движка
namespace Frog {
    class INativeSound;

    /*!
        \brief Интерфейс звуковой компоненты приложения.
        \authors Антон Завьялов, Николай Черемнов
        \version 1.0
        \date Январь 2019
        \see INativeSound

        Интерфейс, обеспечивающий независимый от реализации
        доступ к созданию звуковых объектов.

        При написании своей реализации компонент приложения,
        следует реализовать этот интерфейс в отдельном классе.
     */
    class AudioComponent
    {
    public:
        AudioComponent();
        virtual ~AudioComponent();

        /*!
         * \brief Создает звуковой объект и дает доступ к нему
         * \param source Путь к звуковому файлу
         * \return Адрес созданного звукового объекта
         */
        virtual INativeSound *createSound(const char *source) = 0;
    };

}

/*! @} End of Doxygen Groups*/

#endif // AUDIOCOMPONENT_H
