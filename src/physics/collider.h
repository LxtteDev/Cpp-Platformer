#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifndef COLLIDER_H_
#define COLLIDER_H_

class Collider {
    public:
        Collider(sf::Sprite& sprite);

        sf::VertexArray& getList();

    private:
        sf::Sprite* mSprite;
        sf::VertexArray points;
};

#endif
