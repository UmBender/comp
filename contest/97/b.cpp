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
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto &i : p) { cin >> i; }
	int l = 0, r = n - 1;
	bool option = false;
	int last = MAX_INT;
	vector<char> ops;
	vector<int> numbers;

	while (r - l >= 1) {
		if (option) {
			// sobe
			if (p[l] > last) {
				ops.push_back('L');
				last = p[l];
				numbers.push_back(p[l]);
				l++;
				option = !option;
				continue;
			}
			if (p[r] > last) {
				ops.push_back('R');
				last = p[r];
				numbers.push_back(p[r]);
				r--;
				option = !option;
				continue;
			}
			if (p[l] > p[r]) {
				ops.push_back('R');
				ops.push_back('L');

				numbers.push_back(p[r]);
				numbers.push_back(p[l]);
				last = p[l];
			} else {
				ops.push_back('L');
				ops.push_back('R');
				numbers.push_back(p[l]);
				numbers.push_back(p[r]);
				last = p[r];
			}
			r--;
			l++;
			option = !option;
			continue;
		} else {
			// desce
			if (p[l] < last) {
				ops.push_back('L');
				last = p[l];
				numbers.push_back(p[l]);
				l++;
				option = !option;
				continue;
			}
			if (p[r] < last) {
				ops.push_back('R');
				last = p[r];
				numbers.push_back(p[r]);
				r--;
				option = !option;
				continue;
			}
			if (p[l] < p[r]) {
				ops.push_back('R');
				ops.push_back('L');
				last = p[l];
				numbers.push_back(p[r]);
				numbers.push_back(p[l]);

			} else {
				ops.push_back('L');
				ops.push_back('R');
				last = p[r];
				numbers.push_back(p[l]);
				numbers.push_back(p[r]);
			}
			r--;
			l++;
			option = !option;
			continue;
		}
	}
	if (r == l) { ops.push_back('L'); }

	numbers.push_back(p[l]);
	for (int i = 0; i < n; i++) { cout << ops[i]; }
	cout << endl;
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
