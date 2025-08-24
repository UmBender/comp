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
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n, m;
	cin >> n >> m;
	vector<int> counter(n);
	vector<string> votes(n);
	for (int i = 0; i < n; i++) { cin >> votes[i]; }
	for (int i = 0; i < m; i++) {
		int ones = 0, zeros = 0;
		for (int j = 0; j < n; j++) {
			if (votes[j][i] == '0') {
				zeros++;

			} else {
				ones++;
			}
		}
		char add = zeros < ones ? '0' : '1';
		if (zeros == 0) { add = '1'; }
		if (ones == 0) { add = '0'; }
		for (int j = 0; j < n; j++) {
			if (votes[j][i] == add) { counter[j]++; }
		}
	}

	int mmax = 0;
	for (int i = 0; i < n; i++) {
		if (counter[i] > mmax) { mmax = counter[i]; }
	}
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (counter[i] == mmax) { pos.push_back(i + 1); }
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i] << " \n"[i == pos.size() - 1];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
