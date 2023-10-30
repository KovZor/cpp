#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix m1(2, 3);
    m1.fillMatrix(0);
    m1.printMatrix();

    Matrix m2;
    m2.fillMatrix(1);
    m2.printMatrix();

    Matrix m3 = m1;
    m3.printMatrix();

    Matrix m4 = std::move(Matrix(2, 2));
    m4.printMatrix();

    cout << "Matrix 5: " << endl;
    Matrix m5(5, 5);
    m5.randomMatrix(1, 5);
    m5.printMatrix();
    cout << "Is Square: " << m5.isSquare() << endl;
    cout << "Rows: " << m5.getRows() << endl << "Cols: " << m5.getCols() << endl;

    cout << "Matrix6: " << endl;
    Matrix m6(5, 5);
    m6.randomMatrix(5, 20);
    m6.printMatrix();

    cout << "Matrix 7: " << endl;
    Matrix m7 = m5 + m6;
    m7.printMatrix();

    cout << "Matrix: 8" << endl;
    m1.fillMatrix(2);
    Matrix mX(3, 2);
    mX.fillMatrix(3);
    Matrix m8 = m1 * mX;
    m8.printMatrix();








    return 0;
}