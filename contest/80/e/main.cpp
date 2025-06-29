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
    string s;
    cin >> s;
    map<char, set<int>>      positions;
    vector<pair<char, char>> qq(q);
    for (auto &[from, to] : qq) {
        cin >> from >> to;
    }
    for (int i = 0; i < n; i++) {
        positions[s[i]].insert(i);
    }
    for (auto &[from, to] : qq) {
        if (from < to) {
            auto removed = positions[from].end();
            removed--;

            int value = *removed;
            positions[from].erase(value);
            positions[to].insert(value);

        } else {
            auto removed = positions[from].begin();
            int  value   = *removed;
            positions[from].erase(value);
            positions[to].insert(value);
        }
    }
    vector<char> poss = {'a', 'b', 'c'};
    for (auto i : poss) {
        for (int posi : positions[i]) {
            s[posi] = i;
        }
    }
    cout << s << endl;
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
