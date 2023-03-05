#include "rigidbody.h"

Rigidbody::Rigidbody(sf::Sprite& sprite): mSprite(&sprite) {
    this->acceleration = sf::Vector2f(0.05f, 0);
    this->position = mSprite->getPosition();

}

void Rigidbody::update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) {
    sf::FloatRect bounds = mSprite->getLocalBounds();

    sf::Vector2f bottomLeft = this->position + sf::Vector2f(0.0f, bounds.height * scaleFactor);
    sf::Vector2f bottomRight = this->position + sf::Vector2f(bounds.width * scaleFactor, bounds.height * scaleFactor);

    this->velocity += this->acceleration + sf::Vector2f(0, 0.2f);

    for (Collider* collider: colliders) {
        sf::Vector2f collidesBottom = collider->checkCollision(bottomLeft, bottomRight, scaleFactor);

        if (collidesBottom.x != -1) {
            this->acceleration = sf::Vector2f(this->acceleration.x, 0.0f);
            this->velocity = sf::Vector2f(this->velocity.x, 0.0f);
            this->position = sf::Vector2f(this->position.x, collidesBottom.y - bounds.height * scaleFactor);

            break;
        }
    }
    this->position += this->velocity * deltaTime;

    mSprite->setPosition(this->position);
}
