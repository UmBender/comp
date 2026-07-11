#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    int k;
    cin >> n >> k;

    vector<vector<int>> a(n);
    vector<int> l(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i];
        vector<int> temp(l[i]);
        a[i] = temp;
        for (int j = 0; j < l[i]; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        int total = c[i] * l[i];

        if (k <= total) {
            int index = (k - 1) % l[i];
            cout << a[i][index] << endl;
            return 0;
        }

        k -= total;
    }

    return 0;
}
