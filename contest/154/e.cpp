#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define endl '\n'
#define int i64
constexpr int MOD = 998244353;

signed main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        int ans = 0, rem = 1, p10 = 1;
        for (int l = 1; l <= 19; l++) {
            rem = (rem * 10) % m;
            int val = (rem - 1 + m) % m;

            int g = gcd(m, val);
            int k = m / g;
            int v = n / k;
            int lo, up;
            if (l == 19) {
                lo = 1000000000000000000LL;
                up = 1000000000000000000LL;
            } else {
                lo = p10;
                up = p10 * 10 - 1;
            }

            if (lo <= n) {
                up = min(up, n);
                int c = up - lo + 1;
                ans = (ans + (c % MOD) * (v % MOD)) % MOD;
            }

            if (l < 18) {
                p10 *= 10;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
