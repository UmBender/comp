// #include <atcoder/all>
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
    do {                                                                       \
        cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                      \
        __dbg(__VA_ARGS__);                                                    \
    } while (0)

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
// using mint = atcoder::modint;

void solution() {
    vector<string> g(10);
    for (auto &i : g) {
        cin >> i;
    }
    int counter = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (g[i - 1][j - 1] == 'X') {
                int x_dist, y_dist;
                if (i >= 6) {
                    x_dist = abs(6 - i);
                } else {
                    x_dist = 5 - i;
                }
                if (j >= 6) {
                    y_dist = abs(6 - j);
                } else {
                    y_dist = 5 - j;
                }
                counter += min(5 - x_dist, 5 - y_dist);
            }
        }
    }
    cout << counter << endl;
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
