#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
    std::cout << "GameScene: Creating" << std::endl;

    // Build level
    this->level.resize(this->X, std::vector<int>(Y, -1));   

    int level[5][10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        // -1, 22, 23, 23, 24, -1, 22, 23, 24, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1,  0,  1,  1,  2,
                         1,  1,  1,  1,  1,  1, 13,  8,  8, 27 }; 

    for (int y = 0; y < int(this->Y); y++)
        for (int x = 0; x < int(this->X); x++)
            this->level[x][y] = level[y][x];

    this->resizer = 1 / float( this->Y * 16 );

    // Create player
    sf::Texture* playerTexture = new sf::Texture();
    playerTexture->loadFromFile("content/sprites/white-character.png");

    this->playerSprite = sf::Sprite(*playerTexture);
    this->playerSprite.setPosition(sf::Vector2f(300.0f, 0.0f));

    this->player = new Player(this->playerSprite);

}

void GameScene::setup() {
    std::cout << "GameScene: Setup" << std::endl;

    // Create map
    this->levelMap = tileSheet->generateMap(10, 5, this->level);
    this->tileCollider = new Collider(this->levelMap);
    points = &(tileCollider->getList());

    // Add to list of colliders
    this->colliders.push_back(tileCollider);

    return;
}

void GameScene::resize(sf::Vector2u prevSize, sf::Vector2u newSize) {
    scale = newSize.y * this->resizer;
    sf::Vector2f scaler = sf::Vector2f((float)prevSize.x / (float)newSize.x, (float)prevSize.y / (float)newSize.y);

    std::cout << "Prev:  " << prevSize.x << ", " << prevSize.y << std::endl;
    std::cout << "New:   " << newSize.x << ", " << newSize.y << std::endl;
    std::cout << "Scale: " << scaler.x << ", " << scaler.y << std::endl;

    this->levelMap.setScale(sf::Vector2f(scale, scale));
    this->levelMap.setPosition(sf::Vector2f(this->levelMap.getPosition().x * scaler.x, this->levelMap.getPosition().x * scaler.y));

    this->playerSprite.setScale(sf::Vector2f(scale, scale));
    // this->playerSprite.setPosition(sf::Vector2f(this->playerSprite.getPosition().x * scaler.x, this->playerSprite.getPosition().x * scaler.y));
    player->rigidbody->position = sf::Vector2f(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y * scaler.y);

    for (int i = 0; i < this->pointScaled.getVertexCount(); i++) { // Debug
        this->pointScaled[i].position = (*points)[i].position * scale;
    }
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    // std::cout << "GameScene: Draw" << std::endl;
    window.clear(sf::Color(49, 198, 247));

    player->update(deltaTime, this->colliders, scale);

    window.draw(this->levelMap);
    window.draw(this->playerSprite);

    window.draw(this->pointScaled); // Debug
}