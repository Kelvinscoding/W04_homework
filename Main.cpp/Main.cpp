#include "p26.h"
#include "p04.h"
#include "p08.h"
#include "p12.h"
#include "p322.h"
#include "p347.h"
#include "p398.h"
#include "p423.h"
#include "p457.h"
#include "p471.h"
#include <iostream>
#include <set>
#include <limits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

void menu();

int main() {
	menu();
	int problem_number;
	do  {
		cin >> problem_number;
		if (!cin) {
			cout << "Invalid input. Press Enter to try again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Press Enter to continue...\n";
			while (true) {
				char c = cin.get();

				if (c == '\n') {
					break;
				}
				else {
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Please press Enter to continue...\n";
				}
			}
			menu();
			continue;
		}
		switch (problem_number) {
		case 0:
			cout << "Exiting the program. Goodbye!\n";
			break;
		case 4: {
			int N;
			cout << "Enter the number of elements in the array, then the elements: ";
			cin >> N;
			if (!cin || N < 1 || N > 100) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			ll* array = new ll[N];
			for (int i = 0; i < N; ++i) {
				cin >> array[i];
				if (!cin) {
					cout << "Invalid input. Press Enter to try again.\n" << endl;
					cin.clear();
					break;
				}
			}
			print_prime(array, N);
			break;
		}
		case 8: {
			int n, i, k;
			vector<ll> arr;
			cout << "Enter the size of the array, the starting position for removing and the number of elements for removing. Then enter all the elements: \n";
			cin >> n >> i >> k;
			if (!cin || n <= 0 || i < 0 || i >= n || i + k > n) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			for (int j = 0; j < n; ++j) {
				ll val;
				cin >> val;
				if (!cin || val <= 0) {
					cout << "Invalid input. Press Enter to try again.\n" << endl;
					cin.clear();
					break;
				}
				arr.push_back(val);
			}
			cout << endl;
			vector<ll> result = remove_elements(arr, i, k);
			for (const auto& value : result) {
				cout << value << " ";
			}
			cout << endl << endl;
			break;
		}
		case 12: {
			int n;
			set<ll> array;
			cout << "Enter the size of the array, then the elements: ";
			cin >> n;
			if (!cin || n < 1) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			for (int i = 0; i < n; ++i) {
				ll val;
				cin >> val;
				if (!cin || val <= 0) {
					cout << "Invalid input. Press Enter to try again.\n" << endl;
					cin.clear();
					break;
				}
				array.insert(val);
			}
			cout << endl;
			cout << second_max(array) << "\n\n";
			break;
		}
		case 26: {
			int m, n;
			vector<ll> arr_a, arr_b;
			cout << "Enter the size of the first and the second array, then the arrays: ";
			cin >> m >> n;
			if (!cin || m <= 0 || n <= 0) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			for (int i = 0; i < m; ++i) {
				ll val;
				cin >> val;
				if (!cin) {
					cout << "Invalid input. Press Enter to try again.\n" << endl;
					cin.clear();
					break;
				}
				arr_a.push_back(val);
			}
			for (int i = 0; i < n; ++i) {
				ll val;
				cin >> val;
				if (!cin) {
					cout << "Invalid input. Press Enter to try again.\n" << endl;
					cin.clear();
					break;
				}
				arr_b.push_back(val);
			}
			same_value(arr_a, arr_b);
			break;
		}
		case 322: {
			cout << "Enter the number of rows and columns, then the elements row by row:\n";
			int row, col;
			cin >> row >> col;
			if (!cin || row <= 0 || col <= 0) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			vector<vector<double>> matrix(row, vector<double>(col));
			bool valid_matrix_input = true;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cin >> matrix[i][j];
					if (!cin) {
						cout << "Invalid input. Press Enter to try again.\n" << endl;
						cin.clear();
						valid_matrix_input = false;
						break;
					}
				}
				if (!valid_matrix_input)
					break;
			}
			cout << endl;
			if (valid_matrix_input)
				sum_row(matrix);
			cout << endl << endl;
			break;
		}
		case 347: {
			cout << "Enter the number of rows and columns, then the elements row by row:\n";
			int row, col;
			cin >> row >> col;
			if (!cin || row <= 0 || col <= 0) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			vector<vector<double>> matrix(row, vector<double>(col));
			bool valid_matrix_input = true;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cin >> matrix[i][j];
					if (!cin) {
						cout << "Invalid input. Press Enter to try again.\n" << endl;
						cin.clear();
						valid_matrix_input = false;
						break;
					}
				}
				if (!valid_matrix_input)
					break;
			}
			cout << endl;
			if (valid_matrix_input)
				cout << "Number of Saddle Points: " << saddle_point(matrix) << "\n\n";
			break;
		}
		case 398: {
			int row, col, n;
			cout << "Enter the number of rows and columns, then the elements row by row, then the number of rotations:\n";
			cin >> row >> col;
			if (!cin || row <= 0 || col <= 0) {
				cout << "Invalid input for rows and columns. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			vector<vector<double>> matrix(row, vector<double>(col));
			bool valid_matrix_input = true;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cin >> matrix[i][j];
					if (!cin) {
						cout << "Invalid input. Press Enter to try again.\n" << endl;
						cin.clear();
						valid_matrix_input = false;
						break;
					}
				}
				if (!valid_matrix_input)
					break;
			}
			cin >> n;
			if (!cin || n <= 0) {
				cout << "Invalid input for the number of rotation. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			cout << endl;
			if (valid_matrix_input) {
				rotate_border_clockwise(matrix, row, col, n);
				cout << "Rotated Matrix:\n";
				for (const auto& r : matrix) {
					for (const auto& val : r) {
						cout << fixed << setprecision(2) << val << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			break;
		}
		case 423: {
			int row, col;
			cout << "Enter the number of rows and columns, then the elements row by row:\n";
			cin >> row >> col;
			if (!cin || row <= 0 || col <= 0) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			vector<vector<int>> matrix(row, vector<int>(col));
			bool valid_matrix_input = true;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cin >> matrix[i][j];
					if (!cin) {
						cout << "Invalid input. Press Enter to try again.\n" << endl;
						valid_matrix_input = false;
						cin.clear();
						break;
					}
				}
				if (!valid_matrix_input)
					break;
			}
			cout << endl;
			if (valid_matrix_input) {
				vector<int> result = spiral(matrix);
				cout << "Spiral sorted values: ";
				for (const auto& val : result) {
					cout << val << " ";
				}
				cout << "\n\n";
			}

			break;
		}
		case 457:{
			int row, col;
			cout << "Enter the number of rows and columns, then the elements row by row:\n";
			cin >> row >> col;
			if (!cin || row <= 0 || col <= 0) {
				cout << "Invalid input. Press Enter to try again.\n";
				cin.clear();
				break;
			}
			else if (row != col) {
				cout << "The matrix must be square in order to be symmetric with respect to the main diagonal.\n\n";
				break;
			}
			vector<vector<double>> matrix(row, vector<double>(col));
			bool valid_matrix_input = true;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cin >> matrix[i][j];
					if (!cin) {
						cout << "Invalid input. Press Enter to try again.\n" << endl;
						cin.clear();
						valid_matrix_input = false;
						break;
					}
				}
				if (!valid_matrix_input)
					break;
			}
			cout << endl;
			if (valid_matrix_input) {
				if (symmetric_to_main_diagonal(matrix)) {
					cout << "The matrix is symmetric with respect to the main diagonal.\n\n";
				}
				else {
					cout << "The matrix is not symmetric with respect to the main diagonal.\n\n";
				}
			}
			break;
		}
			case 471: {
				int rows_a, cols_a, rows_b, cols_b;
				cout << "Enter the number of rows and columns for the first matrix, then the elements row by row:\n";
				cin >> rows_a >> cols_a;
				if (!cin || rows_a <= 0 || cols_a <= 0) {
					cout << "Invalid input. Press Enter to try again.\n";
					cin.clear();
					break;
				}
				vector<vector<int>> mat_a(rows_a, vector<int>(cols_a));
				bool valid_matrixa_input = true;
				for (int i = 0; i < rows_a; ++i) {
					for (int j = 0; j < cols_a; ++j) {
						cin >> mat_a[i][j];
						if (!cin) {
							cout << "Invalid input. Press Enter to try again.\n" << endl;
							cin.clear();
							valid_matrixa_input = false;
							break;
						}
					}
					if (!valid_matrixa_input)
						break;
				}
				cout << "Enter the number of rows and columns for the second matrix, then the elements row by row:\n";
				cin >> rows_b >> cols_b;
				if (!cin || rows_b <= 0 || cols_b <= 0 || cols_a != rows_b) {
					cout << "Invalid input or incompatible matrix dimensions. Press Enter to try again.\n";
					cin.clear();
					break;
				}
				vector<vector<int>> mat_b(rows_b, vector<int>(cols_b));
				bool valid_matrixb_input = true;
				for (int i = 0; i < rows_b; ++i) {
					for (int j = 0; j < cols_b; ++j) {
						cin >> mat_b[i][j];
						if (!cin) {
							cout << "Invalid input. Press Enter to try again.\n" << endl;
							cin.clear();
							valid_matrixb_input = false;
							break;
						}
					}
					if (!valid_matrixb_input)
						break;
				}
				cout << endl;
				if (valid_matrixa_input && valid_matrixb_input) {
					vector<vector<int>> result = multiply(mat_a, mat_b);
					cout << "Product of 2 matrices:\n";
					for (const auto& r : result) {
						for (const auto& val : r) {
							cout << val << " ";
						}
						cout << endl;
					}
					cout << endl;
				}
				break;
			}
			default:
				cout << "Invalid problem number. Press Enter to try again.\n" << endl;
				cin.clear();
				break;
		}

		if (problem_number == 0) {
			break; 
		}

		if (!cin) {
			cin.clear();
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Press Enter to continue...\n";
		while (true) {
			char c = cin.get();

			if (c == '\n') {
				break; 
			}
			else {
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Please press Enter to continue...\n";
			}
		}

		menu();

	} while (true); 
	return 0;
}

void menu() {
	cout << "====================================MAIN MENU==============================================\n";
	cout << "These are the problems implemented:\n";
	cout << "4. Problem P04: Print all the prime numbers in the array\n";
	cout << "8. Problem P08: Remove k consecutive elements from the array starting at a given position i\n";
	cout << "12. Problem P12: Find the second largest number in the array\n";
	cout << "26. Problem P26: Find the common values that appear in both arrays\n";
	cout << "322. Problem 322: Calculate the sum of the values in each row of a matrix of real numbers\n";
	cout << "347. Problem 347: Count the number of Saddle Point in the matrix\n";
	cout << "398. Problem 398: Rotate the values on the border of the matrix clockwise\n";
	cout << "423. Problem 423: Sort the values in the matrix in ascending order in a spiral pattern\n";
	cout << "457. Problem 457: Check if the matrix is symmetric with respect to the main diagonal\n";
	cout << "471. Problem 471: Calculate the product of two matrices\n";
	cout << "0. Exit\n";
	cout << "===========================================================================================\n\n";
	cout << "Enter the problem number you want to test: ";

}