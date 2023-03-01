#include "tiles.h"

Tiles::Tiles(const char* tilesPath, int tileSize): tilesTexture(new sf::Texture()) {
    tilesTexture->loadFromFile(tilesPath);
    sf::Vector2f size(tilesTexture->getSize());

    for (int y = 0; y < size.y / tileSize; y ++) {
        for (int x = 0; y < size.x / tileSize; x ++) {
            sf::IntRect bounds(); // Position, size
        }
    }
}

Tiles::~Tiles() {
    delete tilesTexture;
}

sf::Texture& Tiles::getTexture() {
    return *tilesTexture;
}
