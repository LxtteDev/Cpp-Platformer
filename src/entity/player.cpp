#include "player.h"

#define w sf::Keyboard::W
#define s sf::Keyboard::S
#define a sf::Keyboard::A
#define d sf::Keyboard::D
#define space sf::Keyboard::Space
#define keyPressed(key) (sf::Keyboard::isKeyPressed(key))

Player::Player(sf::Sprite& sprite): Entity(sprite) {}; //: mSprite(sprite), rigidbody(new Rigidbody(sprite)) {};

/* void Player::update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) {
    // Horizontal
    if (keyPressed(a))
        rigidbody->acceleration = sf::Vector2f(-playerSpeed, rigidbody->acceleration.y);
    if (keyPressed(d))
        rigidbody->acceleration = sf::Vector2f(playerSpeed, rigidbody->acceleration.y);
    if ( !keyPressed(a) && !keyPressed(d) )
        rigidbody->acceleration = sf::Vector2f(0.0f, rigidbody->acceleration.y);

    // Vertical
    if ((keyPressed(w) || keyPressed(space)) && this->rigidbody->colliding) {
        rigidbody->position += sf::Vector2f(0.0f, -1.0f);
        rigidbody->velocity = sf::Vector2f(rigidbody->velocity.x, -playerSpeed * 0.4f);
    }

    Entity::update(deltaTime, colliders, scaleFactor);
} */