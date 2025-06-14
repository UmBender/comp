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
    vector<vector<pair<int, int>>> edges(n);
    vector<set<int>>               possible_xor(n);
    queue<pair<int, int>>          elements;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges[a].push_back({w, b});
    }
    elements.push({0, 0});
    while (!elements.empty()) {
        auto [actual_w, node] = elements.front();
        elements.pop();
        for (auto [next_w, next_node] : edges[node]) {
            if (!possible_xor[next_node].count(actual_w ^ next_w)) {
                elements.push({actual_w ^ next_w, next_node});
                possible_xor[next_node].insert(actual_w ^ next_w);
            }
        }
    }
    if (possible_xor[n - 1].empty()) {
        cout << -1 << endl;
    } else {
        cout << *possible_xor[n - 1].begin() << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
