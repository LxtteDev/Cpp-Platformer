#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
    std::cout << "GameScene: Creating" << std::endl;

    const int X = 10;
    const int Y = 5;

    // Pre allocate level data
    this->level.resize(X, std::vector<int>(Y, -1));   

    int level[Y][X] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, 22, 23, 23, 24, -1, 22, 23, 24, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1,  0,  1,  1,  1,  2, -1, -1, -1,
                         1,  1, 13,  8,  8,  8, 27,  1,  1,  1 }; 

    for (int y = 0; y < int(Y); y++)
        for (int x = 0; x < int(X); x++)
            this->level[x][y] = level[y][x];
}

void GameScene::setup() {
    std::cout << "GameScene: Setup" << std::endl;

    this->levelMap = tileSheet->generateMap(10, 5, this->level);
    this->levelMap.setScale(sf::Vector2f(3.0f, 3.0f));

    return;
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    window.clear(sf::Color(49, 198, 247));
    window.draw(this->levelMap);
}