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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> counter(60);
    int         counter_ones = 0;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < n; j++) {
            counter[i] += ((a[j] >> i) % (2)) == 0;
            counter_ones += ((a[j] >> i) & 0b1LL);
        }
    }

    for (int i = 0; i < 60; i++) {
        if (counter[i] && k / counter[i] >= (1LL << i)) {
            counter_ones += counter[i];
            for (int j = 0; j < counter[i]; j++) {
                k -= (1LL << i);
            }
        } else if (k >= (1LL << i) && counter[i]) {
            counter_ones += k / (1LL << i);
            k -= (k / (1LL << i)) * (1LL << i);
        }
    }
    cout << counter_ones << endl;
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
