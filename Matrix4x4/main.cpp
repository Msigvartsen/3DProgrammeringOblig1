
#include "vector3d.h"
#include "vector4d.h"
#include "matrix4x4.h"


int main() {
    Vector3d a(4,0,2);
//    Vector3d x(0,0,0);
//    Vector4d b(a,1);
//    b.printVector();
//    Matrix4x4 matrix;
//    matrix.setToIdentity();
//    matrix*2;
//    matrix.printMatrix();
//    Vector4d c(x,1);
//    c = matrix*b;
//    c.printVector();
//    matrix.rotate(0, Vector3d::getXVector());

//    matrix.rotate(32,Vector3d::getYVector());

//    std::cout << "\n\n\n\n";
//    matrix = matrix.perspectiveProj(9,16,0.1f,10);
//    matrix.printMatrix();

//    matrix = matrix.perspective(90,16/9,0.1,10);
//    std::cout << "\n\n\n\n";
//    matrix.printMatrix();


//    for(int i{0}; i < 10; i++)
//    {
//        a.writeToFile("vectors");
//    }

    a.readFromFile("vectors");

    a.printVectorArray();



//    matrix = matrix.translate(3,4,5);
//    std::cout << "\n\n\n";
//    matrix.printMatrix();
//    //matrix = matrix.transpose();
//    std::cout << "\n\n\n";
//    matrix.printMatrix();
//    std::cout << "\n\n\n";
//    matrix.printMatrix();

//    Matrix4x4 trans;
//    Matrix4x4 rot;
//    Matrix4x4 tr;
//    trans = trans.translate(3,3,3);
//    rot = rot.rotate(90,Vector3d::getXVector());
//    tr = trans*rot;


//    std::cout << "Translate Matrix::\n";
//    trans.printMatrix();
//    std::cout << "\n\n\n Rotation Matrix:\n";
//    rot.printMatrix();

//    std::cout << "\n\n\nTrans*Rot::\n";
//    tr.printMatrix();

//    tr = tr.transpose();
//    std::cout << "\n";
//    tr.printMatrix();


    //    Vector4d b(a,0);
    //    b.printVector();
    //    Vector3d c(0,0,0);
    //    c = b.toVec3d();
    //    c.printVector();
    //    Matrix4x4 mat;
    //    mat.setToIdentity();
    //    mat*2;

    //    mat.printMatrix();
    //    std::cout << "\n\n\n";
    //    mat = mat.scale(3,1,2);
    //    mat.printMatrix();



    //    Matrix4x4 matrise;

    //    Vector3d x;
    //    x = Vector3d::getXVector();
    //    x.printVector();

    //    matrise.rotate(45, Vector3d::getYVector());



    return 0;
}
