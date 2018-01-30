#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>
#include <cmath>
#include <vector>


class Vector3d
{
public:
    Vector3d(float a=0, float b=0, float c = 0);
    const Vector3d& operator= (const Vector3d& v);

    Vector3d operator+ (const Vector3d& v) const;
    Vector3d operator- (const Vector3d& v) const;
    float operator* (const Vector3d& v) const;
    Vector3d operator^ (const Vector3d& v) const;
    friend std::ostream& operator<< (std::ostream& out, const Vector3d& v);
    friend std::istream& operator>> (std::istream &in, Vector3d& v);
    float operator[] (int index) const;
    float length() const;
    void normalize();
    Vector3d operator *(float c) const;
    void printVector();
    void writeToFile(std::string filename);
    void readFromFile(std::string filename);
    float getX() const {return x;}
    float getY() const {return y;}
    float getZ() const {return z;}
    void printVectorArray();

    //Get directional vectors
    static Vector3d getXVector() {return Vector3d(1,0,0);}
    static Vector3d getYVector() {return Vector3d(0,1,0);}
    static Vector3d getZVector() {return Vector3d(0,0,1);}

private:
    float x, y, z;
    std::vector<std::string> mVectorString;
    std::vector<Vector3d> mVectorArray;
};

#endif // VECTOR3D_H
