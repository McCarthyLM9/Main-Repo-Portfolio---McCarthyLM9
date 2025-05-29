#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;
using Matrix = vector<vector<int>>;

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

// Helper function to get submatrix excluding row 'p' and column 'q'
Matrix getSubMatrix(const Matrix& matrix, int p, int q) {
    int n = matrix.size();
    Matrix subMatrix;
    for (int i = 0; i < n; ++i) {
        if (i == p) {
            continue;
        }
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            if (j == q) {
                continue;
            }
            row.push_back(matrix[i][j]);
        }
        subMatrix.push_back(row);
    }
    return subMatrix;
}

int getDet(const Matrix& matrix) {
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n) {
        cerr << "Empty or invalid matrix. Exiting..." << endl;
        return INT_MIN;
    }

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }

    int det = 0;
    
    for (int j = 0; j < n; j++) {
        Matrix subMat = getSubMatrix(matrix, 0, j);
        int sign = (j % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][j] * getDet(subMat);
    }
    
    return det;
}

int main() {
    int n;
    cout << "Enter n for n x n matrix to compute determinant: ";
    cin >> n;
    cout << endl;

    Matrix matrix = inputMatrix(n, n);
    cout << endl;

    printMatrix(matrix);
    cout << endl;

    int det = getDet(matrix);

    if (det == INT_MIN) {
        cerr << "Empty or invalid matrix detected. Cannot compute determinant." << endl;
        return -1;
    }
    else {
        cout << "Determinant: " << det << endl;
    }

    return 0;
}