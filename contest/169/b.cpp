#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
    int n, v;
    cin >> n >> v;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    int mmax = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n && i + j <= v; j++) {
            if (i == j) continue;
            for (int k = 1; k <= n && i + j + k <= v; k++) {
                if (k == i || k == j) continue;

                mmax = max(mmax, w[i] + w[j] + w[k]);
            }
        }
    }
    cout << mmax << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
