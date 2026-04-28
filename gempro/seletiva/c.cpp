#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i: a) {
            cin >> i;
        }
        int mmax = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (dp[a[i]] % 2 == 0) {
                dp[a[i]] = mmax + 1;
            } else {
                dp[a[i]] = max(mmax + 1, dp[a[i]] + 1);
            }
            if (dp[a[i]] % 2 == 0) {
                mmax = max(mmax, dp[a[i]]);
            }
        }
        cout << mmax << endl;
    }


    return 0;
}
