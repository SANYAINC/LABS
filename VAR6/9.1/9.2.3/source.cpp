#include <iostream>
#include <vector>

using namespace std;

vector<vector <double>> multiply(vector<vector <double>>& matrix1, vector<vector <double>>& matrix2);


int main() {

    vector<vector <double>> matrix;
    vector<double> tmp;

    int row, col;
    cout << "Rows: ";
    cin >> row;
    cout << "Cols: ";
    cin >> col;

    if (row != col or row <= 0 or col <= 0) {
        cout << "Wrong size";
        return 1;
    }

    matrix.resize(row, tmp);
    for (int i = 0; i < row; ++i) {
        matrix[i].resize(col, 0);
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Matrix["<<i<<"]["<<j<<"]: ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    int power;
    cout << "Power: ";
    cin >> power;

    if (power <= 0) {
        cout << "Wrong power";
        return 1;
    }

    vector<vector <double>> matrixPower = matrix;
    for (int i = 0; i < power - 1; ++i) {
        matrixPower = multiply(matrixPower, matrix);
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrixPower[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}


vector<vector <double>> multiply(vector<vector <double>>& matrix1, vector<vector <double>>& matrix2) {
    vector<vector <double>> result;
    if (matrix1[0].size() != matrix2.size()) {
        return result;
    }

    vector<double> tmp;

    for (int k = 0; k < matrix1.size(); ++k) {
        result.push_back(tmp);
    }

    double buffer = 0;
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1.size(); ++j) {
            for (int k = 0; k < matrix2.size(); ++k) {
                buffer += matrix1[i][k] * matrix2[k][j];
            }
            result[i].push_back(buffer);
            buffer = 0;
        }
    }

    return result;
}