#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
}

void GameScene::setup() {
    std::cout << "Setup" << std::endl;

    return;
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    sf::Texture& tileTexture = tileSheet->getTexture();
    sf::Sprite sprite(tileTexture);

    window.draw(sprite);
}