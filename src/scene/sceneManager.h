#include "scene.h"
#include <vector>
#include <thread>
#include <memory>

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

class SceneManager {
    public:
        SceneManager();

        int addScene(Scene& scene);
        void switchScene(int id);
        void startRender();

    private:

        sf::RenderWindow gameWindow;

        std::vector<Scene*> scenes;
        Scene* currentScene;
};


#endif
