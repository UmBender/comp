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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<int> dp(a.back() + 1, MAX_INT);
    int         all_gcd = a[0];
    for (int i = 1; i < n; i++) {
        all_gcd = __gcd(all_gcd, a[i]);
    }
	int counterfind = 0;
    for (int i = 0; i < n; i++) {
        if (all_gcd == a[i]) {
            counterfind ++;
        }
    }
	if(counterfind) {
		cout << a.size() - counterfind << endl;
		return;
	}

    for (int i = 0; i < n; i++) {
        dp[a[i]] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = dp.size() - 1; j >= all_gcd; j--) {
            if (dp[j] != MAX_INT) {
                int pos = __gcd(j, a[i]);
                dp[pos] = min(dp[j] + 1, dp[pos]);
            }
        }
    }
    int counter = dp[all_gcd];
    cout << counter + a.size() - 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
