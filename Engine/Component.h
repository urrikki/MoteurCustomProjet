#pragma once
#include "Framework.h"

enum class ComponentType {
    Base,
    MeshRenderer,
    Camera,
    Collider,

};

class GameObject;

class Component {
protected:
    GameObject* gameObject;

public:
    Component(GameObject* gameObject);
    virtual ~Component();

    virtual void update(float deltaTime) = 0;
    virtual ComponentType getType() const;
};

class MeshRendererComponent : public Component {
public:
    MeshRendererComponent(GameObject* gameObject);
    virtual ~MeshRendererComponent();

    virtual void update(float deltaTime) override;
    virtual ComponentType getType() const override;
};

class CameraComponent : public Component {
public:
    CameraComponent(GameObject* gameObject);
    virtual ~CameraComponent();

    virtual void update(float deltaTime) override;
    virtual ComponentType getType() const override;
};

class ColliderComponent : public Component {
public:
    ColliderComponent(GameObject* gameObject);
    virtual ~ColliderComponent();

    virtual void update(float deltaTime) override;
    virtual ComponentType getType() const override;
};
