
/*
	Project: Project01
	Due Date: 10/09/25
	Description: This C++ program represents a 2D matrix which will include a menu that allows the user to specify and input 2 matrices for operations.
				 This menu will also allow the user to apply various operations upon the matrices.
*/

#include "Matrix.h"
#include <fstream>

void displayMenu()
{
    cout << "~~~~~ MATRIX MENU ~~~~~" << endl;
    cout << "1. Input Matrix A (manual)" << endl;
    cout << "2. Input Matrix B (manual)" << endl;
    cout << "3. Load Matrix A from file" << endl;
    cout << "4. Load Matrix B from file" << endl;
    cout << "5. Display Matrices" << endl;
    cout << "6. Add" << endl;
    cout << "7. Subtract" << endl;
    cout << "8. Dot Multiply" << endl;
    cout << "9. Scalar Multiply" << endl;
    cout << "10. Increment Matrix A" << endl;
    cout << "11. Print Diagonal of A" << endl;
    cout << "0. Exit" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter choice: ";
}

Matrix loadFile(const string& filename)
{
    ifstream inFile(filename);
    Matrix m;
    inFile >> m;
    inFile.close();
    return m;
}

int main()
{
    Matrix A, B, result;
    int choice;

    do
    {
        // Display menu
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: // Input Matrix A
            cin >> A;
            break;
        case 2: // Input Matrix B
            cin >> B;
            break;
        case 3: // Load Matrix A from file
        {
            string file;
            cout << "Enter filename: ";
            cin >> file;
            A = loadFile(file);
            break;
        }
        case 4: // Load Matrix B from file
        {
            string file;
            cout << "Enter filename: ";
            cin >> file;
            B = loadFile(file);
            break;
        }
        case 5: // Display Matrices
            cout << "Matrix A:" << A;
            cout << "Matrix B:" << B;
            break;
        case 6: // Add
            result = A + B;
            cout << "Result (A+B):" << result;
            break;
        case 7: // Subtract
            result = A - B;
            cout << "Result (A-B):" << result;
            break;
        case 8: // Dot Multiply
            result = A * B;
            cout << "Result (A*B):" << result;
            break;
        case 9: // Scalar Multiply
        {
            int scalar;
            cout << "Enter scalar: ";
            cin >> scalar;
            result = A * scalar;
            cout << "Result (A*" << scalar << "):" << result;
            break;
        }
        case 10: // Increment A
            ++A;
            cout << "Matrix A incremented:" << A << endl;
            break;
        case 11: // Print Diagonal of A
            A.PrintDiagonal();
            break;
        case 0: // Exit
            cout << "Exiting..." << endl;
            break;
        default: // Invalid choice
            cout << "ERROR: Invalid Input" << endl;
        }
    } while (choice != 0);

    return 0;
}
