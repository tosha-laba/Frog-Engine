#include "Tilemap.h"
#include "../Utils/BoundingBox.h"

Tilemap::Tilemap()
{

}

Tilemap::Tilemap(Tileset *graphic, int tilesHoriz, int tilesVert, char *tiles)
    : Entity(graphic, 0, 0), tilesHoriz(tilesHoriz), tilesVert(tilesVert), tiles(tiles)
{
    graphic->setTiles(tiles, tilesHoriz, tilesVert);
    side = graphic->getSide();
}

bool Tilemap::isCollidingWithRect(int rx, int ry, int rw, int rh)
{
    for (int i = 0; i < tilesVert; i++) {
        for (int j = 0; j < tilesHoriz; j++) {
            int tileType = *(tiles + i * tilesHoriz + j);

            if (tileType != 0 && Frog::BoundingBox::checkCollision(rx, ry, rw, rh, x + side * j, y + side * i, side, side))
                return true;
        }
    }

    return false;
}
