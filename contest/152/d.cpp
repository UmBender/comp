#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        int ops = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < x) {
                int needed = x - a[i];
                ops += (needed + i - 1) / i;
                if (ops > k) {
                    return false;
                }
            }
        }
        return true;
    };

    int l = 1, r = 2e18;
    int ans = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
