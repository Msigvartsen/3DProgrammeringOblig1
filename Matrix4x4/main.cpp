
#include "vector3d.h"
#include "vector4d.h"
#include "matrix4x4.h"


int main() {
    Vector3d a(4,0,2);
    Vector3d x(0,0,0);
    Vector4d b(a,1);




    //Legger inn 5 vectors i .txt fil
    for(int i{0}; i < 5; i++)
    {
        a.writeToFile("vectors");
    }

    //Leser vektor fra fil, putter inn i et array
    a.readFromFile("vectors");
    a.printVectorArray();

    std::cout << "\n\n";
    Matrix4x4 matrix;
    matrix.setToIdentity();
    std::cout << "\n\n";

    matrix = matrix.rotate(90, Vector3d::getXVector());
    matrix.printMatrix();
//    Matrix4x4 inv;
//    matrix.setMatrix();
//    inv = matrix.inverse();
//    matrix.printMatrix();
//    std::cout << "Inverse: \n";
//    inv.printMatrix();

    return 0;
}
