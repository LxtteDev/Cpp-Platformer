#include "sceneManager.h"

SceneManager::SceneManager(): gameWindow(sf::VideoMode(800, 600), "Platformer") {}

int SceneManager::addScene(Scene& scene) {
    std::cout << "SceneManager: Adding scene" << std::endl;
    scenes.push_back(&scene);

    if (scenes.size() == 1) SceneManager::switchScene(0);
    return scenes.size() - 1;
}

void SceneManager::switchScene(int id) {
    std::cout << "SceneManager: Switching scene" << std::endl;
    this->gameWindow.clear();

    this->currentScene = scenes[id];
    this->currentScene->setup();
    this->currentScene->resize(this->gameWindow.getSize(), this->gameWindow.getSize());

    std::cout << "SceneManager: Switched" << std::endl;
}

void SceneManager::startRender() {
    sf::Clock clock;
    bool open = 1;

    while (open) {
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        sf::Event e;
		while (this->gameWindow.pollEvent(e))
			if (e.type == sf::Event::Closed)
                open = 0;
            else if (e.type == sf::Event::Resized) {
                sf::Vector2f prevSize = this->gameWindow.getView().getSize();
                this->gameWindow.setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
                this->currentScene->resize(sf::Vector2u(prevSize.x, prevSize.y), this->gameWindow.getSize());
            }

        // std::cout << "Drawing scene" << std::endl;
        this->currentScene->draw(this->gameWindow, deltaSeconds);
        this->gameWindow.display();
    }

    this->gameWindow.close();
}

