#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include <iostream>
#include <array>
#include "vector4d.h"
#include <vector>
#include <cmath>
#include <limits>

class Matrix4x4
{
public:
    Matrix4x4();
    void setToIdentity();
    void printMatrix() const;
    void operator* (float c);
    Vector4d operator* (const Vector4d &v) const;
    Matrix4x4 operator* (const Matrix4x4 &m) const;
    Matrix4x4 scale(float x = 1, float y = 1, float z = 1);
    Matrix4x4 rotate(double rotation, Vector3d &dir);
    Matrix4x4 translate(float x, float y, float z);
private:
    std::array<std::array<float, 4>, 4> matrix;
};

#endif // MATRIX4X4_H
