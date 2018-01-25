#ifndef VECTOR4D_H
#define VECTOR4D_H
#include "vector3d.h"
#include <iostream>

class Vector4d
{
public:
    Vector4d();
    Vector4d(Vector3d &v, float a = 0);
    Vector3d toVec3d();
    float operator[] (int index) const;
    void setX(float x) {this->x = x;}
    void setY(float y) {this->y = y;}
    void setZ(float z) {this->z = z;}
    void setW(float w) {this->w = w;}
    float getX() const {return x;}
    float getY() const {return y;}
    float getZ() const {return z;}
    float getW() const {return w;}
    void printVector();
private:
    float x, y, z, w;

};

#endif // VECTOR4D_H
