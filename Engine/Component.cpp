#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject* gameObject) : gameObject(gameObject) {}

Component::~Component() {}

ComponentType Component::getType() const {
    return ComponentType::Base;
}

MeshRendererComponent::MeshRendererComponent(GameObject* gameObject) : Component(gameObject) {}

MeshRendererComponent::~MeshRendererComponent() {}

void MeshRendererComponent::update(float deltaTime) {

}

ComponentType MeshRendererComponent::getType() const {
    return ComponentType::MeshRenderer;
}

CameraComponent::CameraComponent(GameObject* gameObject) : Component(gameObject) {}

CameraComponent::~CameraComponent() {}

void CameraComponent::update(float deltaTime) {

}

ComponentType CameraComponent::getType() const {
    return ComponentType::Camera;
}

ColliderComponent::ColliderComponent(GameObject* gameObject) : Component(gameObject) {}

ColliderComponent::~ColliderComponent() {}

void ColliderComponent::update(float deltaTime) {

}

ComponentType ColliderComponent::getType() const {
    return ComponentType::Collider;
}