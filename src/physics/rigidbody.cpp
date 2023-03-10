#include "rigidbody.h"

sf::Vector2f powerVector(sf::Vector2f a, int power) {
    return sf::Vector2f(pow(a.x, power), pow(a.y, power));
}

Rigidbody::Rigidbody(sf::Sprite& sprite): mSprite(&sprite) {
    this->mass = 1000.0f;

    this->acceleration = sf::Vector2f(0, 0);
    this->position = mSprite->getPosition();

    std::cout << position.x << ", " << position.y << std::endl;
}

void Rigidbody::update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) {
    // std::cout << "Rigidbody: Update" << std::endl;

    sf::FloatRect bounds = mSprite->getLocalBounds();

    sf::Vector2f bottomLeft = this->position + sf::Vector2f(0.0f, bounds.height * scaleFactor);
    sf::Vector2f bottomRight = this->position + sf::Vector2f(bounds.width * scaleFactor, bounds.height * scaleFactor);

    // Drag
    if (this->acceleration.x == 0.0f) {
        float drag = this->velocity.x / (this->mass * dragCoefficient);
        this->velocity -= sf::Vector2f(drag, 0.0f);
    }
    // if (this->acceleration.y == 0.0f)
    //     this->velocity -= sf::Vector2f(0.0f, drag) * deltaTime;

    this->velocity += (this->acceleration + sf::Vector2f(0, gravity)) * deltaTime;
    this->position += this->velocity * deltaTime;

    for (Collider* collider: colliders) {
        // std::cout << "Rigidbody: Iterate" << std::endl;
        sf::Vector2f collidesBottom = collider->checkCollision(bottomLeft, bottomRight, scaleFactor);

        if (collidesBottom.x != -1) {
            this->acceleration = sf::Vector2f(this->acceleration.x, 0.0f);
            this->velocity = sf::Vector2f(this->velocity.x, 0.0f);
            this->position = sf::Vector2f(this->position.x, collidesBottom.y - bounds.height * scaleFactor);

            break;
        }
    }

    // std::cout << "Rigidbody: Setting position" << std::endl;

    mSprite->setPosition(this->position);

    // std::cout << "Rigidbody: Done" << std::endl;
}
