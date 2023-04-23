#include <SFML/Graphics.hpp>
#include <vector>
#include "./collider.h"

#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

const float gravity = 150.0f;
const float dragCoefficient = 0.5f;

class Rigidbody {
    public:
        Rigidbody(sf::Sprite& sprite);

        void update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor);

        bool colliding;
        float mass;

        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;

    private:
        sf::Sprite* mSprite;
};

#endif
