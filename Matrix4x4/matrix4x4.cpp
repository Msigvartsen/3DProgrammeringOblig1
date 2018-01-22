#include "matrix4x4.h"
#include <iostream>

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
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            matrix[i][j] *= c;
        }
    }
}

Vector4d Matrix4x4::operator*(const Vector4d &v) const
{
    float temp;
    float tempSum;
    Vector4d vec;
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        tempSum = 0;
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            switch(j) {
            case 0:
                temp = v.getX();
                break;
            case 1:
                temp = v.getY();
                break;
            case 2:
                temp = v.getZ();
                break;
            case 3:
                temp = v.getW();
                break;
            default:
                std::cout << "Error in switch\n";
                break;
            }
            //Regn ut matrise*vektor
            tempSum += matrix[i][j] * temp;
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
            break;
        }
        std::cout << "\n";
    }
    return vec;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &m) const
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

void Matrix4x4::scale(float x, float y, float z)
{

}








