#ifndef TILEMAP_H
#define TILEMAP_H

#include "../Entity.h"
#include "../Utils/INativeImage.h"
#include "../FG.h"

/*!
 * \brief Графический объект тайловой карты
 *
 * Берет на вход изображение image, состоящее из тайлов размером side * side
 * На основе информации в двухмерном векторе отрисовывает карту.
 *
 * Поддерживается возможность отрисовки видимой части карты, путем установки
 * границ отрисовки.
 */
class Tileset : public Frog::Graphic
{
public:
    Tileset();
    Tileset(Frog::INativeImage *image, int side) : image(image), side(side) {}
    virtual ~Tileset() {}

    //! Проходит по двухмерному массиву tiles заданного размера и отрисовывает
    //! тайлы указанного типа, расчитывая тип по смещению в исходном изображении
    void render(int x, int y) {
        if (tiles != nullptr && image != nullptr && Frog::FG::graphics != nullptr) {
            int cullingX = cullingStartHoriz >= 0 ? cullingStartHoriz : 0;
            int cullingY = cullingStartVert >= 0 ? cullingStartVert : 0;
            int cullingXU = cullingStartHoriz + visibleHoriz <= tilesHoriz
                    ? cullingStartHoriz + visibleHoriz
                    : tilesHoriz;
            int cullingYU = cullingStartVert + visibleVert <= tilesVert
                    ? cullingStartVert + visibleVert
                    : tilesVert;

            for (int i = cullingY; i < cullingYU; i++) {
                for (int j = cullingX; j < cullingXU; j++) {
                    int imageOffset = *(tiles + i * tilesHoriz + j);

                    if (imageOffset != 0) {
                        Frog::FG::graphics->drawImage(image, x + j * side, y + i * side,
                                                  (imageOffset - 1) * side, 0, side, side);
                    }
                }
            }
        }
    }

    /*!
     * \brief Устанавливает массив с информацией о тайлах и его размеры
     * \param tiles
     * \param tilesHoriz
     * \param tilesVert
     */
    void setTiles(char *tiles, int tilesHoriz, int tilesVert) {
        this->tiles = tiles;
        this->tilesHoriz = tilesHoriz;
        this->tilesVert = tilesVert;
        this->visibleHoriz = tilesHoriz;
        this->visibleVert = tilesVert;
    }

    /*!
     * \brief Устанавливает диапазон отрисовки
     * \param cullingHoriz Максимальное количество отрисовываемых тайлов по горизонтали
     * \param cullingVert Максимальное количество отрисовываемых тайлов по вертикали
     */
    void setCulling(int cullingHoriz, int cullingVert) {
        cullingStartHoriz = cullingHoriz;
        cullingStartVert = cullingVert;
    }

    /*!
     * \brief Устанавливает левую границу отрисовки
     * \param visibleHoriz Старт отрисовки по горизонтали
     * \param visibleVert Старт отрисовки по вертикали
     */
    void setVisibleTiles(int visibleHoriz, int visibleVert) {
        this->visibleHoriz = visibleHoriz;
        this->visibleVert = visibleVert;
    }

    /*!
     * \brief Получает размер тайла
     * \return Размер тайла
     */
    int getSide() { return side; }

private:
    Frog::INativeImage *image = nullptr;
    int side = 0;
    int tilesHoriz = 0;
    int tilesVert = 0;

    char *tiles = nullptr;

    int cullingStartHoriz = 0;
    int cullingStartVert = 0;
    int visibleHoriz = 0;
    int visibleVert = 0;
};

/*!
 * \brief Сущность-обертка над графическим объектом тайловой карты
 *
 * Позволяет определить столкновение между произвольным прямоугольником и картой.
 */
class Tilemap : public Frog::Entity
{
public:
    Tilemap();
    Tilemap(Tileset *graphic, int tilesHoriz, int tilesVert, char *tiles);

    bool isCollidingWithRect(int rx, int ry, int rw, int rh);

private:
    int side = 0;
    int tilesHoriz = 0;
    int tilesVert = 0;
    char *tiles = nullptr;
};

#endif // TILEMAP_H
