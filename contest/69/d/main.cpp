// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> counter(2.1E6);
    vector<int> dp(2.1E6);
    vector<int> results(d);
    for (int i : a) {
        counter[i]++;
    }
    int sum = 0;
    if (d == 0) {
        for (auto j : counter) {
            sum += max(j - 1, 0LL);
        }
    } else {
        for (int i = d; i < dp.size() - d; i++) {
            int first            = dp[i - d] + counter[i - d];
            int second           = dp[i] + counter[i];
            dp[i + d]            = min(first, second);
            results[(i + d) % d] = dp[i + d];
        }
        for (int i = 0; i < d; i++) {
            sum += results[i];
        }
    }
    cout << sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
