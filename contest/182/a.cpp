#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    int ans = -1;
    int mmin = 2e18;
    for (int i = 0; i < n; i++) {
        int a, p, d;
        cin >> a >> p >> d;
        int start;
        if (t <= a) {
            start = a;
        } else {
            int k = (t - a + p - 1) / p;
            start = a + k * p;
        }

        int okay = start + d;
        if (okay < mmin) {
            mmin = okay;
            ans = i + 1;
        }
    }
    cout << ans << " " << mmin << endl;

    return 0;
}
