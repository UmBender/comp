// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <numeric>
#include <string>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

bool arbitrary_base(int value, int base) {
	vector<int> parts;
	while (value) {
		parts.push_back(value % base);
		value /= base;
	}
	reverse(parts.begin(), parts.end());
	for (int i = 0; i < parts.size() / 2; i++) {
		if (parts[i] != parts[parts.size() - 1 - i]) { return false; }
	}
	return true;
}

int convert_pali_odd(int value) {
	int middle = value % 10;
	value /= 10;
	int shift = 100;
	int acc = middle;
	while (value) {
		acc *= 10;
		acc += shift * (value % 10);
		acc += (value % 10);
		value /= 10;
		shift *= 100;
	}
	return acc;
}
int convert_pali_even(int value) {
	int acc = 0;
	int shift = 10;
	while (value) {
		acc *= 10;
		acc += shift * (value % 10);
		acc += (value % 10);
		value /= 10;
		shift *= 100;
	}
	return acc;
}

void solution() {
	int a, n;
	cin >> a >> n;
	int sum = 0;
	for (int i = 1; i <= (int)1E6; i++) {
		int odd = convert_pali_odd(i);
		if (odd > n) { break; }
		bool odd_base = arbitrary_base(odd, a);
		if (odd_base) { sum += odd; }
	}
	for (int i = 1; i <= (int)1E6; i++) {
		int even = convert_pali_even(i);
		if (even > n) { break; }
		bool even_base = arbitrary_base(even, a);
		if (even_base) { sum += even; }

	}
	cout << sum << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
