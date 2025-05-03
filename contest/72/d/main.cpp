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

vector<pair<int, vector<bool>>> cost_ani;
int                             n, m;

vector<vector<int>> ka;
int                 dfs(vector<int> &ani_counter, int actual) {
    bool test = true;
    for(auto i: ani_counter) {
        if(i < 2) {
            test= false;
        }
    }
    if (actual >= n ) {
        if(test) {
            return 0;
        }else{
            return MAX_INT;
        }
    }
    for (int j = 0; j < m; j++) {

        ani_counter[j] += 2 * (cost_ani[actual].second[j] ? 1 : 0);
    }
    int actual_cost = 2 * cost_ani[actual].first;

    int minimal     = MAX_INT;
    for (int i = 0; i < 2; i++) {

        minimal = min(minimal, dfs(ani_counter, actual + 1) + actual_cost);
        actual_cost -= cost_ani[actual].first;
        for (int j = 0; j < m && i != 2; j++) {
            ani_counter[j] -= (cost_ani[actual].second[j] ? 1 : 0);
        }
    }

    minimal = min(minimal, dfs(ani_counter, actual + 1) + actual_cost);
    return minimal;
}

void solution() {
    cin >> n >> m;
    vector<int> c(n);
    for (auto &i : c) {
        cin >> i;
    }
    ka = vector<vector<int>>(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        ka[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> ka[i][j];
            ka[i][j]--;
        }
    }
    cost_ani = vector<pair<int, vector<bool>>>(n, {0, vector<bool>(m)});
    for (int i = 0; i < m; i++) {
        for (auto j : ka[i]) {
            cost_ani[j].second[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cost_ani[i].first = c[i];
    }
    vector<int> ani_counter(m);
    int minimal = dfs(ani_counter, 0);
    cout << minimal << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
