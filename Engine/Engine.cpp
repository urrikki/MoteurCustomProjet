#include <iostream>
#include "Transform.h"

// Surcharge de l'opérateur << pour XMFLOAT4X4
std::ostream& operator<<(std::ostream& os, const DirectX::XMFLOAT4X4& matrix)
{
    os << "[ " << matrix.m[0][0] << " " << matrix.m[0][1] << " " << matrix.m[0][2] << " " << matrix.m[0][3] << " ]" << std::endl;
    os << "[ " << matrix.m[1][0] << " " << matrix.m[1][1] << " " << matrix.m[1][2] << " " << matrix.m[1][3] << " ]" << std::endl;
    os << "[ " << matrix.m[2][0] << " " << matrix.m[2][1] << " " << matrix.m[2][2] << " " << matrix.m[2][3] << " ]" << std::endl;
    os << "[ " << matrix.m[3][0] << " " << matrix.m[3][1] << " " << matrix.m[3][2] << " " << matrix.m[3][3] << " ]" << std::endl;

    return os;
}

int main()
{
    TRANSFORM transform;

    std::cout << "mSca :" << transform.mSca << std::endl;
}


