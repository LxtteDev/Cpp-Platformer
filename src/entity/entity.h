#include <SFML/Graphics.hpp>
#include "../physics/rigidbody.h"

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
    public:
        Entity(sf::Sprite& sprite);

        void update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor);

        Rigidbody* rigidbody;

        private:

        sf::Sprite& mSprite;
};

#endif
