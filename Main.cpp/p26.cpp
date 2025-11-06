#include "p26.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;

void same_value(const vector<ll>& arr_a, const vector<ll>& arr_b) {
	cout << endl;
	int m = arr_a.size();
	int n = arr_b.size();
	unordered_map<ll, int> map_a, map_b;
	for (ll i : arr_a) {
		map_a[i]++;
	}
	for (ll i : arr_b) {
		map_b[i]++;
	}
	bool has_common = false;
	for (const auto& pair : map_a) {
		ll var = pair.first;
		int cnt_a = pair.second;
		if (map_b.count(var)) {
			has_common = true;
			int cnt_b = map_b[var];
			for (int j = 0; j < max(cnt_a, cnt_b); ++j) {
				cout << var << " ";
			}
		}
	}
	if (!has_common) {
		cout << "No common values.";
	}
	cout << endl << endl;

}