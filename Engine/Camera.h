#pragma once
#include "Framework.h"
#include "Component.h"

class Camera : public Component {

public:
    Camera(GameObject* gameObject);
    virtual ~Camera();

    virtual void update(float deltaTime) override;
};