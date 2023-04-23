#include <vector>
#include "rigid.h"

#ifndef COLLISION_H_
#define COLLISION_H_

class Collision {
    public:
        Collision();

        void update(sf::RenderWindow& window);
        void addObject(StaticBody& object);

    private:
        std::vector<StaticBody*> objects;
};

#endif
