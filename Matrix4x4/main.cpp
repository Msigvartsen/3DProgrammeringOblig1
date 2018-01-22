
#include "vector3d.h"
#include "vector4d.h"
#include "matrix4x4.h"


int main() {
    Vector3d a(1.4,2.1,3.2);
    Vector4d b(a,0);
    b.printVector();
    Vector3d c(0,0,0);
    c = b.toVec3d();
    c.printVector();
    Matrix4x4 mat;
    mat.setToIdentity();
    mat*2;


    mat.printMatrix();
    std::cout << "\n\n\n";
    mat = mat.scale(3,1,2);
    mat.printMatrix();



    Matrix4x4 matrise;

    Vector3d x(0,1,0);
    matrise.rotate(90.f, x);



    return 0;
}
