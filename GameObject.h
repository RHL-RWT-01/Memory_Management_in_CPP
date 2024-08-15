//
// Created by Rahul on 8/15/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <memory>

class GameObject {
public:
    int x, y;
    int health;

    GameObject(int x, int y, int health);
    ~GameObject();

    void update();
    void render() const;
    bool isDead() const;
};

#endif // GAMEOBJECT_H
