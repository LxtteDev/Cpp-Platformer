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
        sf::Sprite& getSprite(int id);

        sf::Sprite& generateMap(int X, int Y, std::vector<std::vector<int>> level);

    private:
        int tileSize;
        std::vector<sf::Sprite*> tiles;
        sf::Texture* tilesTexture;
};

#endif
