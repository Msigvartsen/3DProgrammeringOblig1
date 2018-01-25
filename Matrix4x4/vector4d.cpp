#include "vector4d.h"
#include <iostream>

Vector4d::Vector4d()
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

Vector4d::Vector4d(Vector3d &v, float a)
{
    x = v.getX();
    y = v.getY();
    z = v.getZ();
    w = a;
}

Vector3d Vector4d::toVec3d()
{
    return {x, y, z};
}

float Vector4d::operator[](int index) const
{
    switch (index) {
    case 0:
        return x;
        break;
    case 1:
        return y;
        break;
    case 2:
        return z;
        break;
    case 3:
        return w;
        break;
    default:
        break;
    }
}


void Vector4d::printVector()
{
    std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ")\n";
}
