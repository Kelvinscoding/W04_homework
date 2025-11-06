#include "p08.h"
#include <vector>
using namespace std;
using ll = long long;

vector<ll> remove_elements(const vector<ll>& arr, int position, int num) {
	vector<ll> res = arr;
	res.erase(res.begin() + position, res.begin() + position + num);
	return res;
}