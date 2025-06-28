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

void solution() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (auto &i : s) { cin >> i; }
	int begin = s.front();
	int end = s.back();
	sort(s.begin(), s.end());
	int counter = 0;
	int actual = 0;
	if (begin * 2 >= end) {
		cout << 2 << endl;
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == begin) {
			counter = 1;
			actual = i;
		}
	}
	while (s[actual] != end) {
		if (s[actual] * 2 >= end) {
			counter++;
			break;
		}
		if (s[actual + 1] > s[actual] * 2) {
			cout << -1 << endl;
			return;
		}
		int new_actual = actual + 1;
		for (int i = actual + 2; i < s.size(); i++) {
			if (s[i] <= s[actual] * 2) {
				new_actual = i;
			} else {
				break;
			}
		}
		counter++;
		actual = new_actual;
	}
	cout << counter << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
