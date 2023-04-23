#include "gameScene.h"

GameScene::GameScene(): tileSheet(new Tiles("content/sprites/game-tiles-01.png", 16)) {
    std::cout << "GameScene: Creating" << std::endl;

    // Build level
    std::vector<std::vector<int>> level;
    level.resize(this->X, std::vector<int>(Y, -1));   

    int mapLevel[5][10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, 22, 23, 23, 24, -1, 22, 23, 24, -1,
                        // -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1,  0,  1, -1, -1,
                         1,  1,  1,  1,  1,  1, 13,  8,  8, 27 }; 

    for (int y = 0; y < int(this->Y); y++)
        for (int x = 0; x < int(this->X); x++)
            level[x][y] = mapLevel[y][x];

    this->groundSprite = tileSheet->generateMap(10, 5, level);
    // this->resizer = 1 / float( this->Y * 16 );

    // Create player
    // sf::Texture* playerTexture = new sf::Texture();
    // playerTexture->loadFromFile("content/sprites/white-character.png");

    // this->playerSprite = sf::Sprite(*playerTexture);
    // this->playerSprite.setPosition(sf::Vector2f(100.0f, 200.0f));

    // this->player = new Player(this->playerSprite);

}

void GameScene::setup() {
    std::cout << "GameScene: Setup" << std::endl;

    // Create map
    // this->tileCollider = new Collider(this->levelMap);
    // points = &(tileCollider->getList());

    // Add to list of colliders
    // this->colliders.push_back(tileCollider);

    // this->pointScaled.setPrimitiveType(sf::Lines);

    return;
}

void GameScene::resize(sf::Vector2u prevSize, sf::Vector2u newSize) {
    // scale = newSize.y * this->resizer;

    // // Resize map to get scaler
    // sf::FloatRect preScaled = this->levelMap.getGlobalBounds();
    // this->levelMap.setScale(sf::Vector2f(scale, scale));
    // sf::FloatRect post = this->levelMap.getGlobalBounds();
    // sf::Vector2f scaler = sf::Vector2f(post.width / preScaled.width, post.height / preScaled.height);
    // if (prevSize.x == newSize.x && prevSize.y == newSize.y) scaler = sf::Vector2f(1.0f, 1.0f);

    // std::cout << "Prev:  " << prevSize.x << ", " << prevSize.y << std::endl;
    // std::cout << "New:   " << newSize.x << ", " << newSize.y << std::endl;
    // std::cout << "Scale: " << scaler.x << ", " << scaler.y << std::endl;

    // this->levelMap.setPosition(sf::Vector2f(this->levelMap.getPosition().x * scaler.x, this->levelMap.getPosition().x * scaler.y));

    // this->playerSprite.setScale(sf::Vector2f(scale, scale));
    // this->player->rigidbody->position = sf::Vector2f(this->player->rigidbody->position.x * scaler.x, this->player->rigidbody->position.y * scaler.y);

    // this->pointScaled.clear();

    // for (int x = 0; x < this->points->getVertexCount(); x++) {
    //     sf::Vector2f position = (*points)[x].position * scale;
    //     this->pointScaled.append(position);
    // }
}

void GameScene::draw(sf::RenderWindow& window, float deltaTime) {
    // std::cout << "GameScene: Draw" << std::endl;
    window.clear(sf::Color(49, 198, 247));

    // player->update(deltaTime, this->colliders, scale);

    window.draw(this->groundSprite);
    // window.draw(this->playerSprite);

    // window.draw(this->pointScaled); // Debug
}