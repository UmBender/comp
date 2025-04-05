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
    vector<int> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    bool           it_possible = true;
    int            equal       = 0;
    pair<int, int> equal_val   = {-1, -1};
    map<int, int>  base;
    map<int, int>  dual;
    for (int i = 0; i < n; i++) {
        base[a[i]] = b[i];
        dual[b[i]] = a[i];
    }
    for (auto [i, j] : base) {
        if (i == j) {
            equal_val = {i, j};
            equal++;
        }
        if (dual[j] != i) {
            it_possible = false;
        }
    }

    if (!it_possible || (equal != (n & 1))) {
        cout << -1 << endl;
        return;
    }
    map<pair<int, int>, int> pair_pos;
    vector<pair<int, int>>   value_in_pos(n);
    for (int i = 0; i < n; i++) {
        pair_pos[{a[i], b[i]}] = i;
        value_in_pos[i]        = {a[i], b[i]};
    }

    vector<pair<int, int>> moves;
    if (n & 1) {
        if (value_in_pos[n / 2] != equal_val) {
            int actual_pos = pair_pos[equal_val];
            moves.push_back({actual_pos + 1, n / 2 + 1});
            swap(pair_pos[equal_val], pair_pos[value_in_pos[n / 2]]);
            swap(value_in_pos[actual_pos], value_in_pos[n / 2]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        auto [aa, bb] = value_in_pos[i];
        if (pair_pos[{bb, aa}] != n - 1 - i) {
            int pos_target                    = pair_pos[{bb, aa}];
            pair_pos[{bb, aa}]                = n - 1 - i;
            pair_pos[value_in_pos[n - 1 - i]] = pos_target;
            moves.push_back({pos_target + 1, n - i});
            swap(value_in_pos[n - 1 - i], value_in_pos[pos_target]);
        }
    }
    cout << moves.size() << endl;
    for (auto [i, j] : moves) {
        cout << format("{} {}", i, j) << endl;
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
