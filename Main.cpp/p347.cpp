#include "p347.h"
#include <vector>
using namespace std;

int saddle_point(const vector<vector<double>>& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	bool isMincol = true;
	double val;
	int val_col = 0, saddlepoint_cnt = 0;
	for (int i = 0; i < row; ++i) {
		val = matrix[i][0];
		for (int j = 0; j < col; ++j) {
			if (matrix[i][j] > val) {
				val = matrix[i][j];
				val_col = j;
			} //find the max in the row
		}
		for (int k = 0; k < row; ++k) { //check if it's also the min in the column
			if (matrix[k][val_col] < val) {
				isMincol = false;
				break;
			}
		}
		if (isMincol) {
			saddlepoint_cnt++;
		}
	}
	return saddlepoint_cnt;
}