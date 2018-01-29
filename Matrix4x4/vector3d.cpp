#include "vector3d.h"
#include <iostream>
#include <fstream>

Vector3d::Vector3d(float a, float b, float c): x(a), y(b), z(c)
{
}

const Vector3d &Vector3d::operator= (const Vector3d &v)
{
    return Vector3d(x = v.x, y = v.y, z = v.z);
}

Vector3d Vector3d::operator+ (const Vector3d &v) const
{
    return Vector3d(x + v.x, y + v.y, z + v.z);
}

Vector3d Vector3d::operator- (const Vector3d &v) const
{
    return Vector3d(x - v.x, y - v.y, z - v.z);
}

float Vector3d::operator* (const Vector3d &v) const
{
    //Dot product
    return (x * v.x + y * v.y + z * v.z);
}

Vector3d Vector3d::operator ^(const Vector3d &v) const
{
    //CrossProduct
    return {y*v.z - z*v.y, z*v.x - x * v.z, x * v.y - y * v.x};
}

std::ostream& operator<<(std::ostream &out, const Vector3d &v)
{
    out << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return out;
}

std::ostream& operator>>(std::ostream &in, Vector3d &v)
{

}

float Vector3d::operator[](int index) const
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
    default:
        break;
    }
    return 0;
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

void Vector3d::writeToFile(std::string filename)
{
    std::ofstream printFile;
    printFile.open("../" + filename + ".txt", std::ios::app);
    if(!printFile)
    {
        std::cerr << "Error writing to file " << filename;
        exit(1);
    }
    printFile << *this << "\n";
    printFile.close();
}

