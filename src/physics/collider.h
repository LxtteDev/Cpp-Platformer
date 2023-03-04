#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifndef COLLIDER_H_
#define COLLIDER_H_

const float threshold = 0.01f;

class Collider {
    public:
        Collider(sf::Sprite& sprite);

        sf::VertexArray& getList();
        bool checkCollision(sf::Vector2f point, float scaleFactor);

    private:
        sf::Sprite* mSprite;
        sf::VertexArray points;
};

#endif