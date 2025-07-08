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
	vector<int> counter('z' - 'a' + 1);
	int n;
	string s;
	cin >> n >> s;
	for (char i : s) {
		int pos = i - 'a';
		counter[pos]++;
	}
	set<pair<int, char>> scount;
	for (int i = 'a'; i <= 'z'; i++) {
		int pos = i - 'a';
		if (counter[pos]) scount.insert({counter[pos], (char)i});
	}
	auto [_, from] = *scount.begin();
	auto iter = scount.end();
	iter--;
	auto [_, to] = *iter;
	if (to == from) {
		cout << s << endl;
		return;
	}
	string ns = s;
	for (int i = 0; i < n; i++) {
		if (ns[i] == from) {
			ns[i] = to;
			break;
		}
	}
	cout << ns << endl;
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
