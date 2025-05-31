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
    vector<int>  a(n);
    vector<bool> acessed(n, false);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int, int>> dp(n);
    queue<int>             q;
    q.push(0);
    dp[0] = {a[0], 0};
    while (!q.empty()) {
        int actual = q.front();
        q.pop();
        acessed[actual] = true;
        for (int next : adj[actual]) {
            if (acessed[next]) {
                continue;
            }
            dp[next].first  = dp[actual].second + a[next];
            dp[next].second = max(0LL, dp[actual].first - a[next]);
            q.push(next);
        }
    }
    vector<int> resp(n);
    for (int i = 0; i < n; i++) {
        resp[i] = dp[i].first;
    }
	for(int i =0; i < n; i++) {
		cout << resp[i] << " \n"[i==n-1];
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
