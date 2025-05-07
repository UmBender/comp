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

vector<vector<int>> adj;
vector<int>         kv;
set<int>            should_insert;
void dfs(set<int> &used_nodes, set<int> &actual_path, int actual_node,
         int last_node) {
    actual_path.insert(actual_node);
    if (should_insert.count(actual_node)) {
        for (auto i : actual_path) {
            used_nodes.insert(i);
        }
        actual_path.clear();
    }
    for (int next_node : adj[actual_node]) {
        if (next_node == last_node) {
            continue;
        }
        dfs(used_nodes, actual_path, next_node, actual_node);
    }
    if (!should_insert.count(actual_node) && actual_path.count(actual_node)) {
        actual_path.erase(actual_node);
    }
}
void solution() {
    int n, k;
    cin >> n >> k;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    kv = vector<int>(k);
    for (auto &i : kv) {
        cin >> i;
        i--;
    }

    for (auto i = 0; i < k; i++) {
        should_insert.insert(kv[i]);
    }
    set<int> used_nodes = {kv[0]};
    should_insert.erase(kv[0]);
    set<int> actual_path;
    for (auto i : adj[kv[0]]) {
        dfs(used_nodes, actual_path, i, kv[0]);
    }

    cout << used_nodes.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
