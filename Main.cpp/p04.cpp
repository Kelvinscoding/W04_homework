#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

bool is_prime(ll n) {
	bool prime = true;
	if (n == 1)
		prime = false;
	else if (n % 2 == 0 && n > 2)
		prime = false;
	else {
		for (ll i = 3; i <= sqrt(n); ++i) {
			if (n %i == 0) {
				prime = false;
				break;
			}
		}
	}
	return prime;

}

void print_prime(ll* array, int size) {
	cout << endl;
	int cnt_prime = 0;
	vector<ll> prime;
	for (int i = 0; i < size; ++i) {
		if (is_prime(array[i])) {
			prime.push_back(array[i]);
			++cnt_prime;
		}
	}
	cout << cnt_prime << endl;
	for (const auto& val : prime)
		cout << val << " ";
	cout << endl << endl;
	return;
}