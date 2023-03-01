#include "scene/sceneManager.h"
#include "game/mainScene.h"

int main(int, char**) {
    MainScene scene;

    SceneManager sManager;
    sManager.addScene(scene);
    sManager.startRender();
}
