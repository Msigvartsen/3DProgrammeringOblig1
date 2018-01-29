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
                tempMatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
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
    std::cout << "identity in rotate()\n";
    rotationMatrix.printMatrix();
    float cosValue = cos(rotation * (pi / 180));
    float sinValue = sin(rotation * (pi / 180));

    if(cosValue <= std::numeric_limits<float>::epsilon())   //if cos(rotate) inf close to 0.
    {
        cosValue = 0;
    }

    if(dir.getX() == 1)
    {
        rotationMatrix.matrix[1][1] = cosValue;
        rotationMatrix.matrix[1][2] = -sinValue;
        rotationMatrix.matrix[2][1] = sinValue;
        rotationMatrix.matrix[2][2] = cosValue;
        std::cout << "Rotate X\n";

    }
    else if(dir.getY() == 1)
    {
        //std::cout << "rotate y";
        rotationMatrix.matrix[0][0] = cosValue;
        rotationMatrix.matrix[0][2] = sinValue;
        rotationMatrix.matrix[2][0] = -sinValue;
        rotationMatrix.matrix[2][2] = cosValue;
    }
    else
    {
        //std::cout << "rotate z";
        rotationMatrix.matrix[0][0] = cosValue;
        rotationMatrix.matrix[0][1] = -sinValue;
        rotationMatrix.matrix[1][0] = sinValue;
        rotationMatrix.matrix[1][1] = cosValue;
    }

    return rotationMatrix;
}

Matrix4x4 Matrix4x4::translate(float x, float y, float z)
{
    Matrix4x4 translateMatrix;
    translateMatrix.setToIdentity();
    //Translate - Fra mattebok
    translateMatrix.matrix[0][3] = x;
    translateMatrix.matrix[1][3] = y;
    translateMatrix.matrix[2][3] = z;

    //Translate for openGL
    //    translateMatrix.matrix[3][0] = x;
    //    translateMatrix.matrix[3][1] = y;
    //    translateMatrix.matrix[3][2] = z;

    return translateMatrix;
}


//annen versjon av perspektiv, der man legger inn field of view og aspect ration. Noe usikker på denne.
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

//Fra boka - burde fungere
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

Matrix4x4 Matrix4x4::transpose()
{
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{i+1}; j < matrix.size(); j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    return *this;
}

Matrix4x4 Matrix4x4::gaussElimination()
{

}

Matrix4x4 Matrix4x4::inverse()
{
    Matrix4x4 inverseMatrix;
    inverseMatrix.setToIdentity();

    bool done{false};
    bool help{false};
    while(!done)
    {
        //Setter matrise til trappeform
        for(unsigned int i{0}; i < matrix.size(); i++)
        {
            if(matrix[i][i] != 1)
            {
                double factor = matrix[i][i];
                for(unsigned int j{0}; j < matrix.size(); j++)
                {
                    if(factor != 0)
                    {
                        matrix[i][j] /= factor;
                        inverseMatrix.matrix[i][i] /= factor;
                    }
                    else
                    {
                        matrix[i][j] += findRow(i);
                        help = true;
                    }
                }
                if(help)
                {
                    i--;
                    help = false;
                }
            }
            printMatrix();
            bool test{false};
            int row{0};
            int col{0};
            while(!test)
            {
                double tmp = matrix[row][col];
                for(unsigned int j{0}; j < matrix.size(); j++)
                {
                    matrix[row][col] -= tmp*matrix[row+1][j];
                    inverseMatrix.matrix[row][j] -= tmp*inverseMatrix.matrix[row+1][j];
                    if(matrix[row][row] == 1 && matrix[row][col] == 0)
                    {
                        row++;
                    }
                }
                if(row > 3)
                {
                    test = true;
                }
            }
            //            for(unsigned int i{0}; i < matrix.size()-1; i++)
            //            {
            //                double tmp = matrix[i][i+1];
            //                for(unsigned int j{0}; j < matrix.size(); j++)
            //                {

            //                    matrix[i][j] -= tmp*matrix[i+1][j+1];
            //                    inverseMatrix.matrix[i][j] -= tmp*inverseMatrix.matrix[i+1][j+1];

            //                }
            //            }
            done = true;
        }
    }

    return inverseMatrix;
}

void Matrix4x4::setMatrix()
{
    std::cout << "insert matrix:\n";
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        for(unsigned int j{0}; j < matrix.size(); j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

Matrix4x4 Matrix4x4::test()
{

        Matrix4x4 mat;
        for (unsigned column = 0; column < 4; ++column) {
            // Swap row in case our pivot point is not working
            if (matrix[column][column] == 0) {
                unsigned big = column;
                for (unsigned row = 0; row < 4; ++row)
                    if (fabs(matrix[row][column]) > fabs(matrix[big][column])) big = row;
                // Print this is a singular matrix, return identity ?
                if (big == column) fprintf(stderr, "Singular matrix\n");
                // Swap rows
                else for (unsigned j = 0; j < 4; ++j) {
                    std::swap(matrix[column][j], matrix[big][j]);
                    std::swap(mat.matrix[column][j], mat.matrix[big][j]);
                }
            }
            // Set each row in the column to 0
            for (unsigned row = 0; row < 4; ++row) {
                if (row != column) {
                    float coeff = matrix[row][column] / matrix[column][column];
                    if (coeff != 0) {
                        for (unsigned j = 0; j < 4; ++j) {
                            matrix[row][j] -= coeff * matrix[column][j];
                            mat.matrix[row][j] -= coeff * mat.matrix[column][j];
                        }
                        // Set the element to 0 for safety
                        matrix[row][column] = 0;
                    }
                }
            }
        }
        // Set each element of the diagonal to 1
        for (unsigned row = 0; row < 4; ++row) {
            for (unsigned column = 0; column < 4; ++column) {
                mat.matrix[row][column] /= matrix[row][row];
            }
        }

        return mat;
    }



float Matrix4x4::findRow(int index)
{
    for(unsigned int i{0}; i < matrix.size(); i++)
    {
        if(matrix[i][index] != 0)
        {
            return matrix[i][index];
        }
    }
    return 0;
}







