#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifndef TILES_H_
#define TILES_H_

class Tiles {
    public:
        Tiles(const char* tilesPath, int tileSize);
        ~Tiles();

        sf::Texture& getTexture();

    private:
        std::vector<sf::Sprite*> tiles;
        sf::Texture* tilesTexture;
};

#endif
