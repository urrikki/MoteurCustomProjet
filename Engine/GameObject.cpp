#include "GameObject.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::update(float deltaTime) {
    for (auto& component : components) {
        component->update(deltaTime);
    }
}

void GameObject::setTexture(std::unique_ptr<Texture> texture) {
    this->texture = std::move(texture);
}

Texture* GameObject::getTexture() const {
    return texture.get();
}