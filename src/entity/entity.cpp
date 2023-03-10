#include "entity.h"

Entity::Entity(sf::Sprite& sprite): mSprite(sprite), rigidbody(new Rigidbody(sprite)) {};

void Entity::update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) {
    // std::cout << "Entity: Update" << std::endl;
    rigidbody->update(deltaTime, colliders, scaleFactor);
    // std::cout << "Entity: Done" << std::endl;
}
