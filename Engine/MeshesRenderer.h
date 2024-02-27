#pragma once
#include "Framework.h"
#include "Component.h"

class MeshesRenderer : public Component {
    // Attributs et méthodes spécifiques au rendu de mesh
public:
    MeshesRenderer(GameObject* gameObject);
    virtual ~MeshesRenderer();

    virtual void update(float deltaTime) override;
};