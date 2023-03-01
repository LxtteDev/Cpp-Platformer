#include "../scene/scene.h"

#pragma once
#ifndef MAINSCENE_H_
#define MAINSCENE_H_

class MainScene : public Scene {
    public:
        void setup() override;
        void draw(sf::RenderWindow& window, float deltaTime) override;
};

#endif
