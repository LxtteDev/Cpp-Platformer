#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
    std::cout << "GameScene: Creating" << std::endl;

    // Pre allocate level data
    this->level.resize(this->X, std::vector<int>(Y, -1));   

    int level[5][10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        // -1, 22, 23, 23, 24, -1, 22, 23, 24, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1,  0,  1,  1,  1,  2, -1, -1, -1,
                         1,  1, 13,  8,  8,  8, 27,  1,  1,  1 }; 

    for (int y = 0; y < int(this->Y); y++)
        for (int x = 0; x < int(this->X); x++)
            this->level[x][y] = level[y][x];

    this->resizer = 1 / float( this->Y * 16 );
}

void GameScene::setup() {
    std::cout << "GameScene: Setup" << std::endl;

    this->levelMap = tileSheet->generateMap(10, 5, this->level);

    this->tileCollider = new Collider(this->levelMap);
    points = &(tileCollider->getList()); // Debug
    this->pointScaled = *points; // Debug

    this->levelMap.setScale(sf::Vector2f(3.0f, 3.0f));

    return;
}

void GameScene::resize(sf::Vector2u newSize) {
    float scale = newSize.y * this->resizer;
    this->levelMap.setScale(sf::Vector2f(scale, scale));

    for (int i = 0; i < this->pointScaled.getVertexCount(); i++) { // Debug
        this->pointScaled[i].position = (*points)[i].position * scale;
    }
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    window.clear(sf::Color(49, 198, 247));
    window.draw(this->levelMap);
    window.draw(this->pointScaled); // Debug
}