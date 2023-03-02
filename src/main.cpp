#include "scene/sceneManager.h"
#include "game/gameScene.h"

int main(int, char**) {
    std::cout << "Main: Creating scenes" << std::endl;
    GameScene game;

    SceneManager sManager;
    sManager.addScene(game);

    std::cout << "Main: Starting renderer" << std::endl;
    sManager.startRender();
}
