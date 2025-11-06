#include <iostream>
#include <vector>
using namespace std;

void sum_row(vector<vector<double>> matrix) {
	int row = 0;
	for (auto it = matrix.begin(); it != matrix.end(); ++it) {
		double sum = 0.0;
		for (auto ite = it->begin(); ite != it->end(); ++ite) {
			sum += *ite;
		}
		++row;
		cout << "Sum of row " << row << " is: " << sum << endl;
	}
}