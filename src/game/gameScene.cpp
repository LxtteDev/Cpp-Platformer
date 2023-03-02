#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
    std::cout << "GameScene: Creating" << std::endl;

    int X = 5;
    int Y = 5;

    // Pre allocate level data
    this->level.resize(Y, std::vector<int>(X, 0));   

    int level[5][5] = { 3,  3,  3,  3,  3,
                        3, 12, 13, 14,  3,
                        3,  3,  3,  3,  3, 
                        3,  0,  1,  2,  3, 
                        1,  5,  5,  5,  1 };

    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            this->level[x][y] = level[x][y];
}

void GameScene::setup() {
    std::cout << "GameScene: Setup" << std::endl;

    this->levelMap = tileSheet->generateMap(5, 5, this->level);
    this->levelMap.setScale(sf::Vector2f(3.0f, 3.0f));

    return;
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    window.clear();
    window.draw(this->levelMap);
}