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

int bs(vector<pair<int, int>> &arr, int v) {
    int            l     = 0;
    int            r     = arr.size() - 1;
    pair<int, int> value = {-1, -1};
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m].first <= v) {
            value = arr[m];
            r     = m - 1;
        } else {
            l = m + 1;
        }
    }

    return value.second + (value.second == -1 ? 0 : 1);
}

void solution() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    vector<pair<int, int>> filter;
    filter.push_back({a[0], 0});
    for (int i = 1; i < n; i++) {
        if (a[i] < filter.back().first) {
            filter.push_back({a[i], i});
        }
    }

    vector<int> result;
    result.reserve(m);
    for (int i = 0; i < m; i++) {
        result.push_back(bs(filter, b[i]));
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
