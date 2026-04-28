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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        map<int, int> dp;
        int acc = 0;
        for (int i = 1; i <= n; i++) {
            int temp = a[i] - i;
            acc += dp[temp];
            dp[temp] += 1;
        }
        cout << acc << endl;



    }

    return 0;
}
