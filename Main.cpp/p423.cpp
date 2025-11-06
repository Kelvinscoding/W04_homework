#include "p423.h"
#include <vector>
using namespace std;

vector<int> spiral(const vector<vector<int>>& mat) {
	int row = mat.size();
	int col = mat[0].size();
	vector<int> res;
	int top_row = 0, last_row = row - 1;
	int right_col = col - 1, left_col = 0;
	int cnt = 0;
	while (true) {
		for (int i = left_col; i <= right_col; ++i) {
			res.push_back(mat[top_row][i]);
			++cnt;
		}
		if (cnt == row * col)
			return res;
		++top_row;
		for (int j = top_row; j <= last_row; ++j) {
			res.push_back(mat[j][right_col]);
			++cnt;
		}
		if (cnt == row * col)
			return res;
		--right_col;
		for (int i = right_col; i >= left_col; --i) {
			res.push_back(mat[last_row][i]);
			++cnt;
		}
		if (cnt == row * col)
			return res;
		--last_row;
		for (int j = last_row; j >= top_row; --j) {
			res.push_back(mat[j][left_col]);
			++cnt;
		}
		if (cnt == row * col)
			return res;
		++left_col;
	}
}