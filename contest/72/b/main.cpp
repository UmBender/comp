// clang-format off
//#include <atcoder/all>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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
//
void rotate(vector<vector<int>> &s) {
    int                 n = s.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = temp[i][j];
        }
    }
}

void solution() {
    int n;
    cin >> n;
    vector<string> input[2];
    input[0] = vector<string>(n);
    input[1] = vector<string>(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    vector<vector<int>> s(n, vector<int>(n)), t(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = input[0][i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = input[1][i][j];
        }
    }
    vector<int> all_dist;
    for (int i = 0; i < 4; i++) {
        all_dist.push_back(i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (t[j][k] != s[j][k]) {
                    all_dist.back()++;
                }
            }
        }
        rotate(s);
    }

    sort(all_dist.begin(), all_dist.end());

    cout << all_dist.front() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
