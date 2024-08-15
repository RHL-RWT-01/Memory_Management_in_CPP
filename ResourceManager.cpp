//
// Created by Rahul on 8/15/2024.
//
#include "ResourceManager.h"
#include <iostream>

Texture::Texture(const std::string& fileName) {
    std::cout << "Loading texture from " << fileName << std::endl;
}

Texture::~Texture() {
    std::cout << "Texture destroyed" << std::endl;
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string& fileName) {
    auto it = textures.find(fileName);
    if (it != textures.end()) {
        return it->second;
    }

    std::shared_ptr<Texture> texture = std::make_shared<Texture>(fileName);
    textures[fileName] = texture;
    return texture;
}
