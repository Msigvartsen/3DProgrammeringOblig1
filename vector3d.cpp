#include "vector3d.h"


Vector3d::Vector3d(float a, float b, float c): x(a), y(b), z(c)
{
}

const Vector3d &Vector3d::operator =(const Vector3d &v)
{
    return {x = v.x, y = v.y, z = v.z};
}

Vector3d Vector3d::operator +(const Vector3d &v) const
{
    return Vector3d(x + v.x, y + v.y, z + v.z);
}

Vector3d Vector3d::operator -(const Vector3d &v) const
{
    return Vector3d(x - v.x, y - v.y, z - v.z);
}

float Vector3d::operator *(const Vector3d &v) const
{
    //Dot product
    return (x * v.x + y * v.y + z * v.z);
}

Vector3d Vector3d::operator ^(const Vector3d &v) const
{
    //kryssprodukt
    return {y*v.z - z*v.y, z*v.x - x * v.z, x * v.y - y * v.x};
}

float Vector3d::length() const
{
    return (std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
}

void Vector3d::normalize()
{
    float l = length();
    x/=l;
    y/=l;
    z/=l;
}

Vector3d Vector3d::operator *(float c) const
{
    return {x * c, y * c, z * c};
}


void Vector3d::printVector()
{
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}
