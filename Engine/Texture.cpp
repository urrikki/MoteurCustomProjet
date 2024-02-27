#include "Texture.h"

Texture::Texture(const std::string& filepath) : filepath(filepath) {}

Texture::~Texture() {}

void Texture::load() {
    // Implémentation pour charger la texture depuis le fichier spécifié par le chemin filepath
}

void Texture::unload() {
    // Implémentation pour décharger la texture
}

std::string Texture::getFilePath() const {
    return filepath;
}