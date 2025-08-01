// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
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
vector<int> osolves(1E6);

vector<int> solves(osolves.size() + 1);

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }

	int acc = 0;
	int actual = 1;
	int counter = 0;
	for (int i = 0; i < a.size(); i++) {
		acc += a[i];
		while (solves[actual] < acc) { actual++; }
		if (solves[actual] == acc) { counter++; }
	}
	cout << counter << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solves[0] = 1;
	for (int i = 1; i < osolves.size(); i++) {
		//
		osolves[i] = (2 * i - 1) * 4 + 4;
	}
	for (int i = 1; i < solves.size(); i++) {
		solves[i] = solves[i - 1] + osolves[i - 1];
	}

	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
