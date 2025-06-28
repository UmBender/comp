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
	string s, t;
	cin >> s >> t;
	set<char> yes;
	for (auto i : t) {
		if (!yes.count(i)) { yes.insert(i); }
	}
	bool result = true;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (!yes.count(s[i - 1])) {
				result = false;
				break;
			}
		}
	}
	if (result) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
