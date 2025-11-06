#include "p12.h"
#include <set>

long long second_max(std::set<long long> arr) {
	auto res = arr.rbegin();
	++res;
	return *res;
}