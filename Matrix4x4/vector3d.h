#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>
#include <cmath>

class Vector3d
{
public:
    Vector3d(float a=0, float b=0, float c = 0);
    const Vector3d &operator =(const Vector3d& v);
    Vector3d operator +(const Vector3d& v) const;
    Vector3d operator -(const Vector3d& v) const;
    float operator * (const Vector3d& v) const;
    Vector3d operator ^ (const Vector3d& v) const;
    float length() const;
    void normalize();
    Vector3d operator *(float c) const;
    void printVector();

    float getX() {return x;}
    float getY() {return y;}
    float getZ() {return z;}

private:
    float x, y, z;
};

#endif // VECTOR3D_H
