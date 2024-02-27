#include "Texture.h"

Texture::Texture(const std::string& filepath) : filepath(filepath) {}

Texture::~Texture() {}

void Texture::load() {
    // Impl�mentation pour charger la texture depuis le fichier sp�cifi� par le chemin filepath
}

void Texture::unload() {
    // Impl�mentation pour d�charger la texture
}

std::string Texture::getFilePath() const {
    return filepath;
}