#include "entity.h"

#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_

const float playerSpeed = 400.0f;

class Player : public Entity {
    public:
        Player(sf::Sprite& sprite);

        // void update(float deltaTime, std::vector<Collider*> colliders, float scaleFactor) override;

    private:
};

#endif
