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
vector<int>         colors;
vector<set<int> *>  subcolors;
vector<vector<int>> adj;
vector<int>         sizes;

void dfs(int actual, int last) {
    int counter = 0;
    for (int next : adj[actual]) {
        counter += next != last;
    }
    if (counter == 0) {
        subcolors[actual] = new set<int>();
        subcolors[actual]->insert(colors[actual]);
        sizes[actual] = 1;
        return;
    } else {
        set<int> *actual_node = NULL;
        for (int next : adj[actual]) {
            if (next != last) {
                dfs(next, actual);
            }
        }
        for (int next : adj[actual]) {
            if (next != last) {
                if (actual_node == NULL) {
                    actual_node = subcolors[next];
                    actual_node->insert(colors[actual]);
                } else {
                    if (actual_node->size() < subcolors[next]->size()) {
                        swap(actual_node, subcolors[next]);
                    }
                    for (int i : *subcolors[next]) {
                        if (!actual_node->count(i)) {
                            actual_node->insert(i);
                        }
                    }
                }
            }
        }
        subcolors[actual] = actual_node;
        sizes[actual]     = actual_node->size();
    }
}

void solution() {
    int n;
    cin >> n;
    colors    = vector<int>(n);
    subcolors = vector<set<int> *>(n);
    for (auto &i : colors) {
        cin >> i;
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sizes = vector<int>(n);

    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << sizes[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
