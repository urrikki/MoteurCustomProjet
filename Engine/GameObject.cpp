#include "GameObject.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}


//Transform& GameObject::getTransform() {
//    return transform;
//}

void GameObject::addComponent(std::unique_ptr<Component> component) {
    components.push_back(std::move(component));
}

Component* GameObject::getComponent(ComponentType type) const {
    for (const auto& component : components) {
        if (component->getType() == type) {
            return component.get();
        }
    }
    return nullptr;
}

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

void GameObject::render() {
    // Logique de rendu du GameObject
}

//void GameObject::handleEvent(const Event& event) {
//
//}