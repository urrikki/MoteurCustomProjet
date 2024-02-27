#pragma once
#include "Framework.h"

class GameObject;

class Component {
protected:
    GameObject* gameObject;

public:
    Component(GameObject* gameObject);
    virtual ~Component();

    virtual void update(float deltaTime) = 0;
};