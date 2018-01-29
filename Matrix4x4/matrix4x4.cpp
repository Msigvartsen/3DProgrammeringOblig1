#include "matrix4x4.h"
#include <iostream>
#include <limits>
#include <cmath>

Matrix4x4::Matrix4x4()
{
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Matrix4x4::setToIdentity()
{
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        matrix[i][i] = 1;
    }
}

void Matrix4x4::printMatrix() const
{
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Matrix4x4::operator*(float c)
{
    for(unsigned int i{0}; i < matrix.size() -1; i++)
    {
        for(unsigned int j{0}; j < matrix.size() -1; j++)
        {
            matrix[i][j] *= c;
        }
    }
}

Vector4d Matrix4x4::operator*(const Vector4d &v) const
{
    float tempSum;
    Vector4d vec;

    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        tempSum = 0;
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            tempSum += matrix[i][j] * v[j];
        }
        switch (i) {
        case 0:
            vec.setX(tempSum);
            break;
        case 1:
            vec.setY(tempSum);
            break;
        case 2:
            vec.setZ(tempSum);
            break;
        case 3:
            vec.setW(tempSum);
            break;
        default:
            std::cout << "Error: Switch(i) :: Matrix4x4 operator* overload\n";
            break;
        }
    }
    return vec;
}

Matrix4x4 Matrix4x4::operator* (const Matrix4x4 &m) const
{
    Matrix4x4 tempMatrix;
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            for(unsigned int k{0}; k < matrix.size(); k++)
            {
                tempMatrix.matrix[i][j] += matrix[k][i] * m.matrix[j][k];
            }
        }
    }

    return tempMatrix;
}

Matrix4x4 Matrix4x4::scale(float x, float y, float z)
{
    Matrix4x4 tempMatrix;
    tempMatrix.matrix[0][0] = x;
    tempMatrix.matrix[1][1] = y;
    tempMatrix.matrix[2][2] = z;
    tempMatrix.matrix[3][3] = 1;
    return tempMatrix;
}

Matrix4x4 Matrix4x4::rotate(float rotation,  const Vector3d &dir)
{
    double pi = 3.14159265;
    Matrix4x4 rotationMatrix;
    rotationMatrix.setToIdentity();
    //fiks avrundinger og nye variabler for cos/sin
    float cosValue = cos(rotation * (pi / 180));
    float sinValue = sin(rotation * (pi / 180));

    if(cosValue <= std::numeric_limits<float>::epsilon())
    {
        cosValue = 0;
    }

    if(dir.getX() == 1)
    {
        rotationMatrix.matrix[1][1] = cosValue;
        rotationMatrix.matrix[1][2] = -sinValue;
        rotationMatrix.matrix[2][1] = sinValue;
        rotationMatrix.matrix[2][2] = cosValue;
        std::cout << "Rotation matrix x:\n";
        rotationMatrix.printMatrix();

    }
    else if(dir.getY() == 1)
    {
        rotationMatrix.matrix[0][0] = cosValue;
        rotationMatrix.matrix[0][2] = sinValue;
        rotationMatrix.matrix[2][0] = -sinValue;
        rotationMatrix.matrix[2][2] = cosValue;
        std::cout << "Rotation matrix y:\n";
        rotationMatrix.printMatrix();
    }
    else
    {
        rotationMatrix.matrix[0][0] = cosValue;
        rotationMatrix.matrix[0][1] = -sinValue;
        rotationMatrix.matrix[1][0] = sinValue;
        rotationMatrix.matrix[1][1] = cosValue;
        std::cout << "Rotation matrix z:\n";
        rotationMatrix.printMatrix();
    }

    return rotationMatrix;
}

Matrix4x4 Matrix4x4::translate(float x, float y, float z)
{
    Matrix4x4 translateMatrix;

    translateMatrix.setToIdentity();

    //Translate - Fra mattebok
//    translateMatrix.matrix[0][3] = x;
//    translateMatrix.matrix[1][3] = y;
//    translateMatrix.matrix[2][3] = z;

    //Translate for openGL
    translateMatrix.matrix[3][0] = x;
    translateMatrix.matrix[3][1] = y;
    translateMatrix.matrix[3][2] = z;

    return translateMatrix;
}



Matrix4x4 Matrix4x4::perspective(float fov, float aspect, float near, float far)
{
    Matrix4x4 tempMatrix;
    double pi = 3.14159265;
    tempMatrix.matrix[0][0] = (1/aspect * (tan(fov/2))) * pi/180;
    tempMatrix.matrix[1][1] = (1/(tan(fov/2))) * pi/180;
    tempMatrix.matrix[2][2] = (-near-far) / (near - far);
    tempMatrix.matrix[2][3] = (2*far*near) / (near-far);
    tempMatrix.matrix[3][2] = 1;
    return tempMatrix;
}

Matrix4x4 Matrix4x4::perspectiveProj(float top,float right, float near, float far)
{
    Matrix4x4 tempMatrix;
    tempMatrix.matrix[0][0] = near/right;
    tempMatrix.matrix[1][1] = near/top;
    tempMatrix.matrix[2][2] = -(far+near) / (far - near);
    tempMatrix.matrix[2][3] = (-2*far*near) / (far - near);
    tempMatrix.matrix[3][2] = -1;
    return tempMatrix;
}







