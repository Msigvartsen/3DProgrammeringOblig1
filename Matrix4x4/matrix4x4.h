#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include <iostream>
#include <array>
#include "vector4d.h"
#include <vector>

class Matrix4x4
{
public:
    Matrix4x4();
    void setToIdentity();
    void printMatrix() const;
    void operator* (float c);
    Vector4d operator* (const Vector4d &v) const;
private:
    std::array<std::array<float, 4>, 4> matrix;
};

#endif // MATRIX4X4_H
