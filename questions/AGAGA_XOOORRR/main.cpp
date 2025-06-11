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
    vector<vector<int>> aa(n, vector<int>(32));
    for (int i = 0; i < n; i++) {
        int actual = a[i];
        for (int j = 31; j >= 0; j--) {
            aa[i][j] = actual % 2;
            actual /= 2;
        }
    }
    vector<int> counter(32);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            counter[j] += aa[i][j];
        }
    }
    for (int i = 0; i < 32; i++) {
        cout << counter[i] << " \n"[i == 31];
    }

    vector<int> positive;
    for (auto i : counter) {
        if (i != 0) {
            positive.push_back(i);
        }
    }
    if (positive.empty()) {
        cout << "YES" << endl;
        return;
    }
    int actual = positive.front();
    for (int i = 1; i < positive.size(); i++) {
        actual = __gcd(actual, positive[i]);
    }
    if (actual == 1) {
        cout << "NO" << endl;
        return;
    }
    vector<int> factors;
    int         divisor = 2;
    while (actual > 1) {
        if (actual % divisor == 0) {
            factors.push_back(divisor);
        }
        while (actual % divisor == 0) {
            actual /= divisor;
        }
        divisor++;
    }
    :
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
