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
        vector<int> c(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : c) {
            cin >> i;
        }
        int acc = 0;
        int mmin = 1e9;
        for (int i = 0; i < n; i++) {
            mmin = min(mmin, c[i]);
            acc += mmin * a[i];
        }
        cout << acc << endl;
    }

    return 0;
}
