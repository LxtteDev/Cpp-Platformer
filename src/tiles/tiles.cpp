#include "tiles.h"

Tiles::Tiles(const char* tilesPath, int tileSize): tilesTexture(new sf::Texture()) {
    tilesTexture->loadFromFile(tilesPath);

    this->tileSize = tileSize;

    sf::Vector2f size(tilesTexture->getSize());
    std::cout << "Tiles: Creating tile sheet (" << size.x / tileSize << ", " << size.y / tileSize << ")" << std::endl;
    
    for (int y = 0; y < int(size.y / tileSize); y++) {
        for (int x = 0; x < int(size.x / tileSize); x++) {
            sf::IntRect bounds(sf::Vector2i(x * tileSize, y * tileSize), sf::Vector2i(tileSize, tileSize)); // Position, size
            sf::Sprite* sprite = new sf::Sprite();
            sprite->setTexture(*tilesTexture);
            sprite->setTextureRect(bounds);

            tiles.push_back(sprite);
        }
    }
}

Tiles::~Tiles() {
    delete tilesTexture;
}

sf::Texture& Tiles::getTexture() {
    return *tilesTexture;
}

sf::Sprite& Tiles::getSprite(int id) {
    return *tiles[id];
}

sf::Sprite& Tiles::generateMap(int X, int Y, std::vector<std::vector<int>> level) {
    std::cout << "Tiles: Creating tile map (" << X * this->tileSize << ", " << Y * this->tileSize << ")" << std::endl;

    sf::RenderTexture* texture = new sf::RenderTexture();
    texture->create(X * this->tileSize, Y * this->tileSize);
    texture->clear(sf::Color::Transparent);

    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int id = level[x][y];
            if (id == -1) continue;
            std::cout << id << std::endl;

            sf::Sprite& tileSprite = this->getSprite(id);
            tileSprite.setPosition(sf::Vector2f(x * this->tileSize, y * this->tileSize));

            texture->draw(tileSprite);
        }
    }

    texture->display();

    sf::Sprite* output = new sf::Sprite(texture->getTexture());
    return *output;
}
