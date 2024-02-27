#pragma once
#include "Framework.h"
#include <string>

class Texture {
private:
    std::string filepath; 

public:
    Texture(const std::string& filepath);
    ~Texture();

    // Méthodes pour charger, décharger, lier, etc. la texture
    void load();
    void unload();

    // Getter pour le chemin du fichier de texture
    std::string getFilePath() const;
};