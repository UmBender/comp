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
    string      s;
    vector<int> a(10);
    int         n = a.size();
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    vector<int> counter(10);

    for (int i = 0; i < n; i++) {
        counter[a[i]]++;
    }
    vector<int> result(10);
    for (int i = 0; i < n; i++) {
        int minimal   = (10 - i) - 1;
        int min_value = 9;
        for (int j = 9; j >= minimal; j--) {
            if (counter[j] > 0) {
                min_value = min(j, min_value);
            }
        }
        result[i] = min_value;
        counter[min_value]--;
    }
    for (int i = 0; i < n; i++) {
        cout << result[i];
    }
    cout << endl;
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
