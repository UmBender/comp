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
	string s;
	cin >> s;
	auto check = [&](int pos) -> bool {
		if (pos + 2 >= s.size()) { return false; }
		string possilbe[2] = {"FFT", "NTT"};
		bool results[2] = {true, true};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < possilbe[i].size(); j++) {
				results[i] &= possilbe[i][j] == s[j + pos];
			}
		}
		return results[0] || results[1];
	};
	bool contains = false;
	for (int i = 0; i < s.size(); i++) { contains |= check(i); }
	dbg(contains);
	if (contains) {
		sort(s.rbegin(), s.rend());
		cout << s << endl;
	} else {
		cout << s << endl;
	}
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
