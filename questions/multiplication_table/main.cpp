#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int l = 1, r = n * n;
    int minimal = r;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int total = (n * n) / 2;

        int counter = 0;
        for (int i = 1; i <= n; i++) {
            int actual = m / i;
            counter += min(actual, n);
        }
        if (counter > total) {
            minimal = m;
            r = m - 1;
        }else {
            l = m + 1;
        }

    }
    cout << minimal << endl;


    return 0;
}
