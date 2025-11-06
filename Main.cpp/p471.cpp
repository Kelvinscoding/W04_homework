#include "p471.h"
#include <vector>
using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& mat_a, const vector<vector<int>>& mat_b) {
	int rows_a = mat_a.size();
	int cols_a = mat_a[0].size();
	int rows_b = mat_b.size();
	int cols_b = mat_b[0].size();
	vector<vector<int>> res(rows_a, vector<int>(cols_b, 0));
	for (int i = 0; i < rows_a; ++i) {
		for (int j = 0; j < cols_b; ++j) {
			for (int k = 0; k < cols_a; ++k) {
				res[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}
	return res;
}