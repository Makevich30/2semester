#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void input_matrix(ifstream& infile, vector<vector<T>>& matrix) {
    int n, m;
    infile >> n >> m;
    matrix.resize(n, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            infile >> matrix[i][j];
        }
    }
}

template <typename T>
void output_matrix(ofstream& outfile, const vector<vector<T>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outfile << matrix[i][j] << " ";
        }
        outfile << endl;
    }
}

template <typename T>
T matrix_norm(const vector<vector<T>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    T norm = 0;
    for (int i = 0; i < n; i++) {
        T max_elem = *max_element(matrix[i].begin(), matrix[i].end());
        norm += max_elem;
    }
    return norm;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    vector<vector<int>> matrix;
    input_matrix(infile, matrix);

    int norm = matrix_norm(matrix);

    outfile << "Matrix norm: " << norm << endl;

    infile.close();
    outfile.close();

    return 0;
}
