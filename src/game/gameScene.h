#include "../scene/scene.h"
#include "../tiles/tiles.h"

#pragma once
#ifndef GAMESCENE_H_
#define GAMESCENE_H_

class GameScene : public Scene {
    public:
        GameScene();

        void setup() override;
        void resize(sf::Vector2u newSize) override;
        void draw(sf::RenderWindow& window, float deltaTime) override;

    private:
        float resizer = 1.0f;
        const int X = 10;
        const int Y = 5;

        Tiles* tileSheet;
        std::vector<sf::Sprite> sprites;

        std::vector<std::vector<int>> level;
        sf::Sprite levelMap;
};

#endif
