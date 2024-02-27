#pragma once
#include "Framework.h"
#include "Component.h"

class MeshesRenderer : public Component {
    // Attributs et m�thodes sp�cifiques au rendu de mesh
public:
    MeshesRenderer(GameObject* gameObject);
    virtual ~MeshesRenderer();

    virtual void update(float deltaTime) override;
};