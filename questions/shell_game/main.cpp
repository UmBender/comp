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
#define int ll
//using mint = atcoder::modint;
// clang-format on

void solution() {

	freopen("shell.in", "r", stdin);
    int n;
	scanf("%lld", &n);
    vector<tuple<int, int, int>> abg(n);
    for (auto &[a, b, g] : abg) {
        cin >> a >> b >> g;
    }
    int maxx = 0;
    for (int i = 1; i <= 3; i++) {
        int actual_pos = i;
        int counter    = 0;
        for (int j = 0; j < n; j++) {
            auto [a, b, g] = abg[j];
            if (a == actual_pos) {
                actual_pos = b;
            } else {
                if (actual_pos == b) {
                    actual_pos = a;
                }
            }
			counter += actual_pos == g;
        }
		maxx = max(maxx, counter);
    }
	freopen("shell.out", "w", stdout);
	printf("%lld\n", maxx);
}

int32_t main() {
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
