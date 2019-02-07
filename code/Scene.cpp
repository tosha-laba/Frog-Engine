#include "Scene.h"
#include "FG.h"

namespace Frog {
    //! Создает пустую сцену без сущностей
    Scene::Scene()
    {

    }

    Scene::~Scene()
    {

    }

    /*!
     * \brief Добавляет сущность на сцену
     * \param entity Добавляемая сущность
     */
    void Scene::addEntity(Entity *entity)
    {
        entities.push_back(std::shared_ptr<Entity>(entity));
    }

    /*!
     * \brief Удаляет сущность со сцены
     * \param entity Адрес удаляемой сущности
     */
    void Scene::removeEntity(Entity *entity)
    {
        entities.erase(std::remove(entities.begin(), entities.end(), std::shared_ptr<Entity>(entity)), entities.end());
    }

    //! Содержит логику, выполняемую при связи сущности и движка в первый раз.
    void Scene::init()
    {

    }

    //! Содержит логику, выполняемую при обновлении кадра, выполняет метод обновления сущностей
    //! При перегрузке следует вызывать метод базового класса
    void Scene::update()
    {
        for (auto e : entities) {
            e->update();
        }
    }

    //! Содержит логику, выполняемую при отрисовке кадра, выполняет отрисовку сущностей
    //! При перегрузке следует вызывать метод базового класса
    void Scene::onDraw()
    {
        for (auto e : entities) {
            e->render();
        }
    }

    /*!
     * \brief Содержит логику, выполняемую при нажатии на клавишу клавиатуры.
     * \param keyCode Код нажатой клавиши.
     */
    void Scene::keyPressed(int keyCode)
    {

    }

    /*!
     * \brief Содержит логику, выполняемую при отпускании клавиши клавиатуры.
     * \param keyCode Код нажатой клавиши.
     */
    void Scene::keyReleased(int keyCode)
    {

    }

    /*!
     * \brief Содержит логику, выполняемую при перемещении мыши по экрану.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     */
    void Scene::mouseMoved(int x, int y)
    {

    }

    /*!
     * \brief Содержит логику, выполняемую при нажатии на кнопку мыши.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     * \param button Код кнопки мыши: 0 - левая, 1 - колесо, 2 - правая
     */
    void Scene::mousePressed(int x, int y, int button)
    {

    }

    /*!
     * \brief Содержит логику, выполняемую при отпускании кнопки мыши.
     * \param x Координата X курсора мыши
     * \param y Координата Y курсора мыши
     * \param button Код кнопки мыши: 0 - левая, 1 - колесо, 2 - правая
     */
    void Scene::mouseReleased(int x, int y, int button)
    {

    }

    /*!
     * \brief Проверяет, нажата ли заданная клавиша
     * \param key Код клавиши
     * \return true - если клавиша с таким кодом нажата, false - иначе
     */
    bool Scene::isPressed(int key)
    {
        auto extracted = FG::keyState.find(key);

        if (extracted != FG::keyState.end()) {
            return extracted->second;
        }

        return false;
    }

}
