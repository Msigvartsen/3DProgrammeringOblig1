
#include "vector3d.h"
#include "vector4d.h"
#include "matrix4x4.h"


int main() {
   Vector3d a(1,1,1);
   Vector3d x(0,0,0);
   Vector4d b(a,1);
   b.printVector();
   Matrix4x4 matrix;
   matrix.setToIdentity();
   matrix*2;
   matrix.printMatrix();
   Vector4d c(x,1);
   c = matrix*b;
   c.printVector();
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
