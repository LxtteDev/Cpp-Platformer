#include "../scene/scene.h"
#include "../tiles/tiles.h"

#pragma once
#ifndef GAMESCENE_H_
#define GAMESCENE_H_

class GameScene : public Scene {
    public:
        GameScene();

        void setup() override;
        void draw(sf::RenderWindow& window, float deltaTime) override;

    private:
        Tiles* tileSheet;
};

#endif
