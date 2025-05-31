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
    int n, q;
    cin >> n >> q;
    vector<int> b(n);
    for (auto &i : b) {
        cin >> i;
    }
    vector<tuple<int, int, int>> xyz(q);
    for (auto &[x, y, z] : xyz) {
        cin >> x >> y >> z;
    }
    reverse(xyz.begin(), xyz.end());
    vector<int>  a       = b;
    bool         is_okay = true;
    vector<bool> are_correct(n, true);
    for (auto [x, y, z] : xyz) {
        are_correct[z - 1] = false;
    }
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
