
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
    mat.printMatrix();
    mat.setToIdentity();
    mat.printMatrix();

    mat*2;
    mat.printMatrix();

    std::cout << "\n\n\n";

    b.printVector();
    b = mat * b;
    b.printVector();
    return 0;
}
