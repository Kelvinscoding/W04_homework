#include <vector>
using namespace std;

bool symmetric_to_main_diagonal(const vector<vector<double>>& mat) {
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = i + 1; j < mat[i].size(); ++j) {
			if (mat[i][j] != mat[j][i]) {
				return false;
			}
		}
	}
	return true;
}