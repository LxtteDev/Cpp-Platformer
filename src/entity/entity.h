#include <SFML/Graphics.hpp>
#include "../physics/rigid.h"

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
    public:
        Entity(sf::Sprite& sprite);

        // virtual void update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor);

        // RigidBody* rigidbody;

    private:
        // sf::Sprite& mSprite;
};

#endif
