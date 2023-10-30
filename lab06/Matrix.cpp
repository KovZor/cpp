#include "Matrix.h"
#include <random>

using namespace std;

Matrix::Matrix(int mRows, int mCols): mRows(mRows), mCols(mCols) {
    mElements = new double* [mRows];
    for(int i = 0; i < mRows; i++){
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = new double* [mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }

    for(int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;

    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;

    cout << "Move constructor!" << endl;
}

Matrix::~Matrix() {
    for(int i = 0; i < mRows; i++){
        delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::printMatrix(ostream &os) const {
    for(int i = 0; i < mRows; i++){
        for(int j = 0; j < mCols; j++){
            os << mElements[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::fillMatrix(double value) {
    for(int i = 0; i < mRows; i++){
        for(int j = 0; j < mCols; j++){
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // Initialize a random device
    mt19937 gen(rd()); // Create a random number gene

    uniform_real_distribution<double> distribution(a, b);

    for(int i = 0; i < mRows; i++){
        for(int j = 0; j < mCols; j++){
            mElements[i][j] = distribution(gen);
        }
    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        // Matrices have different dimensions, so throw an exception
        throw out_of_range("Matrix dimensions do not match");
    }

    Matrix result(x.mRows, x.mCols);

    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }

    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if( x.mCols != y.mRows ){
        throw out_of_range("Matrix dimensions are not compatible for multiplication");
    }

    Matrix result(x.mRows, y.mCols);
    result.fillMatrix(0);

    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            for(int k = 0; k < x.mCols; k++){
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }

    return result;
}

istream& operator>>(istream& is, Matrix& mat) {
    for (int i = 0; i < mat.mRows; i++) {
        for (int j = 0; j < mat.mCols; j++) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.mRows; i++) {
        for (int j = 0; j < mat.mCols; j++) {
            os << mat.mElements[i][j] << ' ';
        }
        os << '\n'; // start a new line for the next row
    }
    return os;
}

double* Matrix::operator[](int index) {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

double* Matrix::operator[](int index) const {
    if (index < 0 || index >= mRows) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[index];
}

Matrix& Matrix::operator=(const Matrix& mat) {
    if (this == &mat) {
        return *this;
    }

    if (mRows != mat.mRows || mCols != mat.mCols) {
        throw std::out_of_range("Matrix dimensions do not match for assignment");
    }

    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }

    return *this;  // Return a reference to the modified object
}

Matrix& Matrix::operator=(Matrix&& mat) {
    if (this == &mat) {
        return *this;
    }

    // Release resources from the current object
    for (int i = 0; i < mRows; i++) {
        delete[] mElements[i];
    }
    delete[] mElements;

    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = mat.mElements;

    // Reset the source matrix
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}









