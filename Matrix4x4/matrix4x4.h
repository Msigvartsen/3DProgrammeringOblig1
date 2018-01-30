#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include <iostream>
#include <array>
#include "vector4d.h"



class Matrix4x4
{
public:
    Matrix4x4();
    void setToIdentity();
    void printMatrix() const;
    void operator* (float c);                                                   //Matrix * Scalar
    Vector4d operator* (const Vector4d &v) const;                               //Matrix * Vector
    Matrix4x4 operator* (const Matrix4x4 &m) const;                             //Matrix * Matrix
    Matrix4x4 scale(float x = 1, float y = 1, float z = 1);
    Matrix4x4 rotate(float rotation, const Vector3d &dir);
    Matrix4x4 translate(float x, float y, float z);
    Matrix4x4 perspective(float fov, float aspect, float near, float far);
    Matrix4x4 perspectiveProj(float top, float right, float near, float far);
    Matrix4x4 transpose(); //Transpose Matrix -- used with openGL
    Matrix4x4 gaussElimination();
    Matrix4x4 inverse();
    void setMatrix();


private:
    std::array<std::array<float, 4>, 4> matrix;
    float findRow(int &index);
};

#endif // MATRIX4X4_H
