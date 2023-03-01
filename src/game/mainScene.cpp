#include "mainScene.h"

void MainScene::setup() {
    std::cout << "Setup" << std::endl;
}

void MainScene::draw(sf::RenderWindow& window, float deltaTime) {
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(100.0f, 100.0f));

    window.draw(shape);
}