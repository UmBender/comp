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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, 1));
    if (m % k == 0) {
        queue<int> elements;
        for (int i = 1; i <= k; i++) {
            elements.push(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int actual = elements.front();
                elements.pop();
                elements.push(actual);
                grid[i][j] = actual;
            }
            int temp = elements.front();
            elements.pop();
            elements.push(temp);
        }

    } else {
        int actual = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = actual;
                actual++;
                actual %= (k + 1);
                actual += actual == 0;
            }
        }
    }
    for (auto &i : grid) {
        for (int j = 0; j < m; j++) {
            cout << i[j] << " \n"[j == m - 1];
        }
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
