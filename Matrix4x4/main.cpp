
#include "vector3d.h"
#include "vector4d.h"
#include "matrix4x4.h"


int main() {
    Vector3d a(4,0,2);
    Vector3d x(0,0,0);
    Vector4d b(a,1);

    Matrix4x4 matrix;
    //    matrix = matrix.rotate(90,Vector3d::getXVector());
    //    matrix.printMatrix();
    // matrix.setMatrix();
    matrix.printMatrix();
    Matrix4x4 inv;
    //    inv = matrix.inverse();
    //    std::cout << "\n\n";
    //    matrix.printMatrix();

    //    std::cout << "\n\n";
    //    inv.printMatrix();
    matrix.setMatrix();
    matrix.printMatrix();
    inv = matrix.test();
    inv.printMatrix();

    return 0;
}
