#include "../scene/scene.h"
#include "../tiles/tiles.h"
#include "../physics/collider.h"
#include "../entity/entity.h"

#pragma once
#ifndef GAMESCENE_H_
#define GAMESCENE_H_

class GameScene : public Scene {
    public:
        GameScene();

        void setup() override;
        void resize(sf::Vector2u prevSize, sf::Vector2u newSize) override;
        void draw(sf::RenderWindow& window, float deltaTime) override;

    private:
        float scale = 1.0f;
        float resizer = 1.0f;
        const int X = 10;
        const int Y = 5;

        Tiles* tileSheet;
        Collider* tileCollider;
        Entity* player;

        std::vector<sf::Sprite> sprites;
        std::vector<std::vector<int>> level;
        std::vector<Collider*> colliders;

        sf::VertexArray* points;
        sf::VertexArray pointScaled;

        sf::Sprite levelMap;
        sf::Sprite playerSprite;
};

#endif
