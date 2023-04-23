#include <vector>
#include <iostream>
#include "static.h"

#ifndef RIGID_H_
#define RIGID_H_

class RigidBody : public StaticBody {
    public:
        RigidBody(Shape* shape);

        void update(sf::RenderWindow& window, std::vector<StaticBody*>& objects) override;

        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        bool colliding = false;

    private:
        sf::Clock clock;
};

#endif
