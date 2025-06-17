// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
    int mat[n][m];
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            cin >> mat[j][k];
        }
    }
    vector<int>         values(100 + 1);
    vector<vector<int>> lines(n, vector<int>(100 + 1));
    vector<vector<int>> columns(m, vector<int>(100 + 1));
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            values[mat[j][k]]++;
            lines[j][mat[j][k]]++;
            columns[k][mat[j][k]]++;
        }
    }
    int real_min = INT_MAX;
    for (int j = 0; j < n; j++) {
        for (int l = 1; l < 101; l++) {
            values[l] -= lines[j][l];
            values[l - 1] += lines[j][l];
        }
        for (int k = 0; k < m; k++) {
            for (int l = 1; l < 101; l++) {
                values[l] -= columns[k][l];
                values[l - 1] += columns[k][l];
            }
            values[mat[j][k]]++;
            int mmin = 0;
            for (int l = 0; l < 101; l++) {
                if (values[l] > 0) {
                    mmin = l;
                }
            }
            values[mat[j][k]]--;

            for (int l = 1; l < 101; l++) {
                values[l] += columns[k][l];
                values[l - 1] -= columns[k][l];
            }
            real_min = min(mmin, real_min);
        }
        for (int l = 1; l < 101; l++) {
            values[l] += lines[j][l];
            values[l - 1] -= lines[j][l];
        }
    }
    cout << real_min << endl;
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
