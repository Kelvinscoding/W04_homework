#include "p398.h"
#include <vector>
using namespace std;

void rotate_border_clockwise(vector<vector<double>>& matrix, int row, int col, int n) {
    vector<double> arr;
    for (int i = 0; i < col; ++i) {
        arr.push_back(matrix[0][i]);
    }
    for (int i = 1; i < row; ++i) {
        arr.push_back(matrix[i][col - 1]);
    }
    for (int i = col - 2; i >= 0; --i) {
        arr.push_back(matrix[row - 1][i]);
    }
    for (int i = row - 2; i > 0; --i) {
        arr.push_back(matrix[i][0]);
    }
    int total = 2 * (row + col) - 4;
    n = n % total;
    vector<double> rotated_arr(total);
    for (int i = 0; i < total; ++i) {
        rotated_arr[(i + n) % total] = arr[i];
    }
    int index = 0;
    for (int i = 0; i < col; ++i) {
        matrix[0][i] = rotated_arr[index++];
    }
    for (int i = 1; i < row; ++i) {
        matrix[i][col - 1] = rotated_arr[index++];
    }
    for (int i = col - 2; i >= 0; --i) {
        matrix[row - 1][i] = rotated_arr[index++];
    }
    for (int i = row - 2; i > 0; --i) {
        matrix[i][0] = rotated_arr[index++];
    }
}