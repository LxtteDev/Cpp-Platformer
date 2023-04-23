#include "rigid.h"

const float gravity = 50.0f;
const float threshold = 1.0f;

RigidBody::RigidBody(Shape* shape): StaticBody(shape) {};

void RigidBody::update(sf::RenderWindow& window, std::vector<StaticBody*>& objects) {
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds();

    this->velocity += (this->acceleration + sf::Vector2f(0.0f, gravity)) * deltaTime;
    this->position += this->velocity * deltaTime;
    StaticBody::update(window, objects);

    sf::FloatRect bounding = this->mShape->getBoundingBox();

    this->colliding = false;
    for (StaticBody* body : objects) {
        if (body == this) continue;

        sf::FloatRect mBounding = body->getBoundingBox();

        // Check in bounding box
        if (inBounding(bounding, mBounding)) {
            sf::Vector2f offset = body->intersects(this->mShape);
            if (offset.x != 0 || offset.y != 0) {
                this->colliding = true;

                this->position += offset;

                if (offset.x > 0)
                    this->velocity.x = std::max(0.0f, this->velocity.x);
                else if (offset.x < 0)
                    this->velocity.x = std::min(0.0f, this->velocity.x);

                if (offset.y > 0)
                    this->velocity.y = std::max(0.0f, this->velocity.y);
                else if (offset.y < 0)
                    this->velocity.y = std::min(0.0f, this->velocity.y);

                break;
            }
        }
    }
}
