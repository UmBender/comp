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
    vector<int> unique;
    int         last = a.front();
    unique.push_back(last);
    for (int i = 0; i < n; i++) {
        if (last != a[i]) {
            unique.push_back(a[i]);
            last = a[i];
        }
    }
    map<int, int> counter;
    map<int, int> dp[2];
    for (int i = 0; i < n; i++) {
        counter[a[i]]++;
    }
    for (int i = 0; i < unique.size(); i++) {
        dp[0][unique[i]] = counter[unique[i]];
        if (dp[0][unique[i]] >= 4) {
            cout << "Yes" << endl;
            return;
        }
        dp[1][unique[i]] =
            max(counter[unique[i]], dp[1][unique[i] - 1] * counter[unique[i]]);
        if (dp[1][unique[i]] >= 4) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
