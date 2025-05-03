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
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!adj[a].count(b)) {
            adj[a].insert(b);
        }
        if (!adj[b].count(a)) {
            adj[b].insert(a);
        }
    }
    if (n != m) {
        cout << "No" << endl;
        return;
    }

    set<int> used;
    set<int> not_used;
    int      actual = 1;
    bool     first  = true;
    bool     worked = true;
    int      begin  = 1;
    while (used.size() != n) {
        if (adj[actual].size() != 2) {
            worked = false;
            break;
        }
        if (first) {
            first    = false;
            int next = *adj[actual].begin();
            used.insert(next);
            actual = next;
        } else {
            int next = -1;
            for (int j : adj[actual]) {
                if (used.count(j)) {
                    continue;
                }
                next = j;
            }
            if (next == -1) {
                worked = false;
                break;
            }
            if (next == 1 && used.size() != n - 1) {
                worked = false;
                break;
            }
            used.insert(next);
            actual = next;
        }
    }
    if (worked && actual == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
