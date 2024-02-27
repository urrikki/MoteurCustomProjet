#include "Transform.h"
#include <iostream>


void TRANSFORM::Identity()
{
    vSca.x = 1.0f; 
    vSca.y = 1.0f;
    vSca.z = 1.0f;

    XMStoreFloat4x4(&mSca, XMMatrixIdentity());

    vDir.x = 0.0f;
    vDir.y = 0.0f;
    vDir.z = 1.0f;

    vRight.x = 1.0f;
    vRight.y = 0.0f;
    vRight.z = 0.0f;

    vUp.x = 0.0f;
    vUp.y = 1.0f;
    vUp.z = 0.0f;

    qRot.x = 0.0f;
    qRot.y = 0.0f;
    qRot.z = 0.0f;
    qRot.w = 1.0f;

    mRot = mSca;

    vPos.x = 0.0f;
    vPos.y = 0.0f;
    vPos.z = 0.0f;

    mPos = mSca;

    matrix = mSca;
    
}

void TRANSFORM::Rotate(float roll, float pitch, float yaw)
{
    //Utiliser qRot dans la fonction 
    
    // Créer un quaternion pour chaque rotation (delta)
    XMVECTOR quatRot;

    XMFLOAT3 axisDir = vDir;
    XMVECTOR quatDir = XMQuaternionRotationAxis(XMLoadFloat3(&axisDir), roll);
    quatRot = quatDir;

    XMFLOAT3 axisRight = vRight;
    XMVECTOR quatRight = XMQuaternionRotationAxis(XMLoadFloat3(&axisRight), pitch);
    quatRot = XMQuaternionMultiply(quatRot, quatRight);

    XMFLOAT3 axisUp = vUp;
    XMVECTOR quatUp = XMQuaternionRotationAxis(XMLoadFloat3(&axisUp), yaw);
    quatRot = XMQuaternionMultiply(quatRot, quatUp);

    // Ajouter la rotation delta à la rotation actuelle de l'objet
    XMStoreFloat4(&qRot, XMQuaternionMultiply(XMLoadFloat4(&qRot), quatRot));

    //Utiliser mRot dans la fonction
    // Convertir le quaternion en une matrice de rotation
    XMMATRIX matRot = XMMatrixRotationQuaternion(XMLoadFloat4(&qRot));

    // Mettre à jour les axes de notre objet (3 vecteurs)
    XMStoreFloat3(&vRight, matRot.r[0]);
    XMStoreFloat3(&vUp, matRot.r[1]);
    XMStoreFloat3(&vDir, matRot.r[2]);
}

