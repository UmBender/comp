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
	vector<int> b(n);
	for (auto &i : b) { cin >> i; }
	map<int, int> counter;
	for (int i = 0; i < n; i++) { counter[b[i]]++; }
	bool okay = true;
	for (auto &[key, value] : counter) {
		if (value % key != 0) {
			okay = false;
			break;
		}
	}

	if (!okay) {
		cout << -1 << endl;
		return;
	}
	int actual = 1;
	map<int, queue<int>> uses;
	for (auto [key, value] : counter) {
		for (int chunks = 0; chunks < value / key; chunks++) {
			for (int volume = 0; volume < key; volume++) {
				uses[key].push(actual);
			}
			actual++;
		}
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = uses[b[i]].front();
		uses[b[i]].pop();
	}
	for (int i = 0; i < n; i++) { cout << a[i] << " \n"[i == n - 1]; }
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
