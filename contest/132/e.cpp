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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

vector<int> build_pi_s(string &s) {
	vector<int> pi_s(s.size());
	int len = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[len]) {
			len++;
			pi_s[i] = len;
		} else {
			while (len > 0) {
				len = pi_s[len - 1];
				if (s[i] == s[len]) {
					len++;
					pi_s[i] = len;
					break;
				}
			}
			if (len == 0) { pi_s[i] = 0; }
		}
	}
	return pi_s;
}

int kmp(string &n, string &m) {
	vector<int> pi_s = build_pi_s(m);
	int i = 0, j = 0;
	while (i < n.size()) {
		if (m[j] == n[i]) {
			i++, j++;
			if (j == m.size()) {
				if (i - j < m.size()) return i - j;
				j = pi_s[j - 1];
			}
		} else {
			if (j != 0) {
				j = pi_s[j - 1];
			} else {
				i++;
			}
		}
	}
	return -1;
}

void solution() {
	string a, b;
	cin >> a >> b;
	string aa = a + a;
	int pos = kmp(aa, b);
	cout << pos << endl;
}
