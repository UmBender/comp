#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;

#define int i64
using namespace std;

int counter = 0;


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> f(n + 1), g(n + 1);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i + 1 <= n) { 
            f[i + 1] += f[i];
            f[i + 1] += g[i];
        }
        if (i + 2 <= n) {
            f[i + 2] += f[i];
            g[i + 2] += 2 * f[i];
            g[i + 1] += g[i];
        }
    }
    cout << f[n] << endl;
}
