#include "collision.h"

Collision::Collision() {
}

void Collision::update(sf::RenderWindow& window) {
    for (auto object : this->objects) {
        object->update(window, this->objects);
    }
}

void Collision::addObject(StaticBody& object) {
    this->objects.push_back( &object );
}