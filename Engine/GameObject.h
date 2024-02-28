#pragma once

#include <vector>
#include <memory>
#include "Component.h"
#include "Texture.h"
#include "Transform.h"

class GameObject {
private:
    std::vector<std::unique_ptr<Component>> components;
    std::unique_ptr<Texture> texture;

public:
    GameObject();
    ~GameObject();

    template <typename T>
    T* addComponent() {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        std::unique_ptr<T> newComponent = std::make_unique<T>(this);
        T* rawPointer = newComponent.get();
        components.push_back(std::move(newComponent));
        return rawPointer;
    }

    void update(float deltaTime);

    void setTexture(std::unique_ptr<Texture> texture);
    Texture* getTexture() const;

    //Transform& getTransform();
    void addComponent(std::unique_ptr<Component> component);
    Component* getComponent(ComponentType type) const;
    void update(float deltaTime);
    void render();
    //void handleEvent(const Event& event);
};