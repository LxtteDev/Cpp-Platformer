#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#ifndef COLLIDER_H_
#define COLLIDER_H_

const float threshold = 1.0f; // Must be within this range to update (In pixels)

class Collider {
    public:
        Collider(sf::Sprite& sprite);

        sf::VertexArray& getList();
        sf::Vector2f checkCollision(sf::Vector2f a, sf::Vector2f b, float scaleFactor);

    private:
        sf::Sprite* mSprite;
        sf::VertexArray points;
};

#endif
