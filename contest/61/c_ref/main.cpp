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
    int                 equal = 0;
    pair<int, int>      equal_pair;
    set<pair<int, int>> ab;
    for (int i = 0; i < n; i++) {
        ab.insert({a[i], b[i]});
        if (a[i] == b[i]) {
            equal++;
            equal_pair = {a[i], a[i]};
        }
    }
    for (auto [i, j] : ab) {
        if (!ab.count({j, i})) {
            cout << -1 << endl;
            return;
        }
    }
    vector<pair<int, int>>   actual(n);
    map<pair<int, int>, int> pos;
    for (int i = 0; i < n; i++) {
        actual[i]         = {a[i], b[i]};
        pos[{a[i], b[i]}] = i;
    }
    if(n%2 ==0 && equal != 0) {
        cout << -1 << endl;
        return;
    }
    if(n%2 == 1 && equal != 1) {
        cout << -1 << endl;
        return;
    }
    if (equal != (n & 1)) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> sw;
    if (n % 2 == 1 && actual[n / 2] != equal_pair) {
        int actual_pos = pos[equal_pair];
        swap(pos[actual[n / 2]], pos[equal_pair]);
        swap(actual[n / 2], actual[actual_pos]);
        sw.push_back({n / 2 + 1, actual_pos + 1});
    }
    for (int i = 0; i < n; i++) {
        auto [aa, bb] = actual[i];
        if (make_pair(bb, aa) != actual[n - i - 1]) {
            int actual_pos = pos[{bb, aa}];
            swap(pos[{bb, aa}], pos[actual[n - i - 1]]);
            swap(actual[actual_pos], actual[n - i - 1]);
            sw.push_back({actual_pos + 1, n - i});
        }
    }
    cout << sw.size() << endl;
    for (auto [i, j] : sw) {
        cout << format("{} {}\n", i, j);
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
