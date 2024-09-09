#pragma once
#include <vector>
#include "GameObject.h"

class SceneManager {
public:
    static SceneManager* SceneManagerInstance;

    void RegisterObject(GameObject* gameobject);
    void RemoveObject(GameObject* gameobject);
    void TickObjects();

    void RenderScene();

    static SceneManager* getInstance()
    {
        if (SceneManagerInstance == NULL)
        {
            SceneManagerInstance = new SceneManager();
            return SceneManagerInstance;
        }
        else
        {
            return SceneManagerInstance;
        }
    }

    SceneManager(SceneManager const&) = delete;
    void operator=(SceneManager const&) = delete;

private:  
    SceneManager();
    ~SceneManager();
public:
    std::vector<GameObject*> m_SceneObjects;
    Renderer renderer;
};

