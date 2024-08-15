//
// Created by Rahul on 8/15/2024.
//


#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <memory>
#include <string>

class Texture {
public:
    Texture(const std::string& fileName);
    ~Texture();
};

class ResourceManager {
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;

public:
    std::shared_ptr<Texture> loadTexture(const std::string& fileName);
};

#endif // RESOURCEMANAGER_H

