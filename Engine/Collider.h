#pragma once
#include "Framework.h"
#include "Component.h"

class Collider : public Component {
    // Attributs et m�thodes sp�cifiques au collider
public:
    Collider(GameObject* gameObject);
    virtual ~Collider();

    virtual void update(float deltaTime) override;
};