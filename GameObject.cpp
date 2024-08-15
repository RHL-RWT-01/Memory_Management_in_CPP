//
// Created by Rahul on 8/15/2024.
//
#include "GameObject.h"

GameObject::GameObject(int x, int y, int health)
    : x(x), y(y), health(health) {
    std::cout << "GameObject created at (" << x << ", " << y << ") with health " << health << std::endl;
}

GameObject::~GameObject() {
    std::cout << "GameObject destroyed at (" << x << ", " << y << ")" << std::endl;
}

void GameObject::update() {
    x += 1;
    y += 1;
}

void GameObject::render() const {
    std::cout << "Rendering GameObject at (" << x << ", " << y << ")" << std::endl;
}

bool GameObject::isDead() const {
    return health <= 0;
}

