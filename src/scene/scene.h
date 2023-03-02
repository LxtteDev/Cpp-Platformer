#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#pragma once
#ifndef SCENE_H_
#define SCENE_H_

class Scene {
    public:
        Scene();

        virtual void setup();
        virtual void resize(sf::Vector2u newSize);
        virtual void draw(sf::RenderWindow& window, float deltaTime);
};

#endif