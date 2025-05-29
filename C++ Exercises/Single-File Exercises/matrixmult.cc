#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();
    Matrix result(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

void printMatrix(const Matrix& matrix) {
    int max_width = 0;
    for (const auto &row : matrix) {
        for (int num : row) {
            int width = to_string(num).length();
            if (width > max_width) {
                max_width = width;
            }
        }
    }

    for (const auto& row : matrix) {
        cout << "(";
        for (size_t j = 0; j < row.size(); j++) {
            cout << setw(max_width) << row[j];
            if (j < row.size() - 1) {
                cout << " ";
            }
        }
        cout << ")\n";
    }
}

Matrix inputMatrix(int rows, int cols) {
    Matrix matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter the number of rows and columns for the first matrix (rowsA x colsA): ";
    cin >> rowsA >> colsA;
    cout << "Enter the number of rows and columns for the second matrix (rowsB x colsB): ";
    cin >> rowsB >> colsB;
    
    if (colsA != rowsB) {
        cerr << "Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix in order to perform matrix multiplication." << endl;
        return 1;
    }

    cout << "Enter the first matrix:\n";
    Matrix A = inputMatrix(rowsA, colsA);

    cout << "Enter the second matrix:\n";
    Matrix B = inputMatrix(rowsB, colsB);

    cout << "The first matrix is:\n";
    printMatrix(A);

    cout << "The second matrix is:\n";
    printMatrix(B);

    cout << "The product of the two matrices is:\n";
    Matrix C = multiplyMatrices(A, B);
    printMatrix(C);

    return 0;
}