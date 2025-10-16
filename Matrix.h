
/*
	Project: Project01
	Due Date: 10/09/25
	Description: This C++ program represents a 2D matrix which will include a menu that allows the user to specify and input 2 matrices for operations.
				 This menu will also allow the user to apply various operations upon the matrices.
*/

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iomanip>
#include <iostream>
using namespace std;

class Matrix
{
private:
    static const int MAX_SIZE = 10;
    int data[MAX_SIZE][MAX_SIZE];
    int rows;
    int cols;

public:
    // Constructors
    Matrix();
    Matrix(int r, int c);

    // Accessors
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    void setValue(int r, int c, int value);
    int getValue(int r, int c) const;

    // Check Validity
    bool MakeValid();
    bool RowColumnMatch(const Matrix& matrix) const;
    bool DotReady(const Matrix& matrix) const;
    bool IsSquare() const;

    // Overloaders
    friend ostream& operator<<(ostream& outFile, const Matrix& m);
    friend istream& operator>>(istream& inFile, Matrix& m);
    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(int scalar) const;           // scalar multiplication
    Matrix operator*(const Matrix& matrix) const; // dot product
    Matrix& operator++();                         // prefix ++
    Matrix operator++(int);                       // postfix ++

    // Other
    void PrintDiagonal() const;
};

#endif
