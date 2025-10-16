
/*
	Project: Project01
	Due Date: 10/09/25
	Description: This C++ program represents a 2D matrix which will include a menu that allows the user to specify and input 2 matrices for operations.
				 This menu will also allow the user to apply various operations upon the matrices.
*/

#include "Matrix.h"

Matrix::Matrix() : rows(0), cols(0)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = 0;
        }
    }
}

void Matrix::setValue(int r, int c, int value)
{
    data[r][c] = value;
}

int Matrix::getValue(int r, int c) const
{
    return data[r][c];
}

bool Matrix::MakeValid()
{
    return (rows > 0 && cols > 0 && rows <= MAX_SIZE && cols <= MAX_SIZE);
}

bool Matrix::RowColumnMatch(const Matrix& matrix) const
{
    return (rows == matrix.rows && cols == matrix.cols);
}

bool Matrix::DotReady(const Matrix& matrix) const
{
    return (cols == matrix.rows);
}

bool Matrix::IsSquare() const
{
    return (rows == cols);
}

ostream& operator<<(ostream& outFile, const Matrix& m)
{
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            // FIXME: adjust width
            outFile << setw(1) << m.data[i][j];
        }
        outFile << endl;
    }
    return outFile;
}

istream& operator>>(istream& inFile, Matrix& m)
{
    cout << "Enter rows and columns: ";
    inFile >> m.rows >> m.cols;
    cout << "Enter matrix values (" << m.rows * m.cols << " positive integers):" << endl;
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            inFile >> m.data[i][j];
        }
    }
    return inFile;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] + matrix.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& matrix) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(int scalar) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    Matrix result(rows, matrix.cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < matrix.cols; ++j)
        {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k)
            {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    return result;
}

// prefix
Matrix& Matrix::operator++()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            ++data[i][j];
        }
    }
    return *this;
}

// postfix
Matrix Matrix::operator++(int)
{
    Matrix temp = *this;
    ++(*this);
    return temp;
}

void Matrix::PrintDiagonal() const
{
    // Check if square
    if (!IsSquare())
    {
        cout << "Matrix is not a square." << endl;
        return;
    }

    // Print diagonal elements if square
    cout << "Diagonal elements: ";
    for (int i = 0; i < rows; ++i)
    {
        cout << data[i][i] << " ";
    }
    cout << endl;
}
