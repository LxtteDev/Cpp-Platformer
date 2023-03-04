#include "rigidbody.h"

Rigidbody::Rigidbody(sf::Sprite& sprite): mSprite(&sprite) {
    this->acceleration = sf::Vector2f(0, 0.2f);
    this->position = mSprite->getPosition();

}

void Rigidbody::update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) {
    sf::Vector2f point = this->position;
    point = sf::Vector2f(point.x + mSprite->getLocalBounds().width * ( scaleFactor / 2.0f ), point.y + mSprite->getLocalBounds().height * scaleFactor);

    for (Collider* collider: colliders) {
        bool collides = collider->checkCollision(point, scaleFactor);

        if (collides) {
            this->acceleration = sf::Vector2f(0.0f, 0.0f);
            this->velocity = sf::Vector2f(0.0f, 0.0f);

            break;
        }
    }

    this->velocity += this->acceleration;
    this->position += this->velocity * deltaTime;

    mSprite->setPosition(this->position);
}
