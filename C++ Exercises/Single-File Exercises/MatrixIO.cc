#include <iostream>
#include <vector>
#include <iomanip>
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
    for (const auto& row : matrix) {
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

int main() {
    int n;
    cout << "Enter n for the n x n matrix: ";
    cin >> n;
    cout << endl;
    Matrix matrix = inputMatrix(n, n);
    cout << endl;
    printMatrix(matrix);
    return 0;
}