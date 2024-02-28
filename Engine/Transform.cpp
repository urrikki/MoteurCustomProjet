#include "Transform.h"
#include <iostream>


void TRANSFORM::Identity()
{
    vSca.x = 1.0f; 
    vSca.y = 1.0f;
    vSca.z = 1.0f;

    mSca._11 = 1.0f;
    mSca._12 = 0.0f;
    mSca._13 = 0.0f;
    mSca._14 = 0.0f;

    mSca._21 = 0.0f;
    mSca._22 = 1.0f;
    mSca._23 = 0.0f;
    mSca._24 = 0.0f;

    mSca._31 = 0.0f;
    mSca._32 = 0.0f;
    mSca._33 = 1.0f;
    mSca._34 = 0.0f;

    mSca._41 = 0.0f;
    mSca._42 = 0.0f;
    mSca._43 = 0.0f;
    mSca._44 = 1.0f;

    //XMStoreFloat4x4(&mSca, XMMatrixIdentity());

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

void TRANSFORM::Rotate(float roll, float yaw ,float pitch )
{   
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

    // Convertir le quaternion en une matrice de rotation (magique)
    XMMATRIX matRot = XMMatrixRotationQuaternion(XMLoadFloat4(&qRot));

    //Passer la matrix en XMFLOAT4X4
    XMStoreFloat4x4(&mRot, matRot);

    // Mettre à jour les axes de notre objet (3 vecteurs)
    vRight.x = mRot._11;
    vRight.y = mRot._12;
    vRight.z = mRot._13;
    vUp.x = mRot._21;
    vUp.y = mRot._22;
    vUp.z = mRot._23;
    vDir.x = mRot._31;
    vDir.y = mRot._32;
    vDir.z = mRot._33;   
}

void TRANSFORM::Rotate(float roll, float pitch, float yaw)
{
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

    // Convertir le quaternion en une matrice de rotation (magique)
    XMMATRIX matRot = XMMatrixRotationQuaternion(XMLoadFloat4(&qRot));

    //Passer la matrix en XMFLOAT4X4
    XMStoreFloat4x4(&mRot, matRot);
}

void TRANSFORM::Scaling(float x, float y, float z)
{
    vSca.x = x;
    vSca.y = y;
    vSca.z = z;
    XMMATRIX scaMat = XMMatrixScaling(x, y, z);
    XMStoreFloat4x4(&mSca, scaMat);
}

void TRANSFORM::Translation(float x, float y, float z)
{
    vPos.x = x;
    vPos.y = y;
    vPos.z = z;
    XMMATRIX traMat = XMMatrixTranslation(x, y, z);
    XMStoreFloat4x4(&mPos, traMat);
}

void TRANSFORM::UpdateWorld()
{
    XMMATRIX worldMat = XMLoadFloat4x4(&mSca) * XMLoadFloat4x4(&mRot) * XMLoadFloat4x4(&mPos);
    XMStoreFloat4x4(&matrix, worldMat);
}
