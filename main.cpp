#include "GameObject.h"
#include "MemoryPool.h"
#include "ResourceManager.h"
#include <vector>
#include <algorithm>
#include <memory>

int main() {
    // Example of using MemoryPool
    MemoryPool bulletPool(10, sizeof(GameObject));

    GameObject* b1 = new (bulletPool.allocate()) GameObject(0, 0, 100);
    GameObject* b2 = new (bulletPool.allocate()) GameObject(10, 10, 50);

    b1->~GameObject();
    bulletPool.deallocate(b1);

    b2->~GameObject();
    bulletPool.deallocate(b2);

    // Example of using ResourceManager
    ResourceManager resourceManager;
    std::shared_ptr<Texture> tex1 = resourceManager.loadTexture("texture1.png");
    std::shared_ptr<Texture> tex2 = resourceManager.loadTexture("texture1.png");

    std::cout << "Tex1 and Tex2 share the same resource: " << (tex1 == tex2) << std::endl;

    // Example of managing GameObjects with STL algorithms
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    gameObjects.push_back(std::make_unique<GameObject>(0, 0, 100));
    gameObjects.push_back(std::make_unique<GameObject>(10, 10, 50));
    gameObjects.push_back(std::make_unique<GameObject>(20, 20, 0));  // Dead object

    std::sort(gameObjects.begin(), gameObjects.end(), [](const std::unique_ptr<GameObject>& a, const std::unique_ptr<GameObject>& b) {
        return a->x < b->x;
    });

    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::unique_ptr<GameObject>& obj) {
        return obj->isDead();
    });

    if (it != gameObjects.end()) {
        std::cout << "Found dead object at (" << (*it)->x << ", " << (*it)->y << ")" << std::endl;
    }

    gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [](const std::unique_ptr<GameObject>& obj) {
        return obj->isDead();
    }), gameObjects.end());

    for (const auto& obj : gameObjects) {
        obj->render();
    }

    return 0;
}
