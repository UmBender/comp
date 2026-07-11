#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n+ 1);
    for (int i = 1; i < n + 1; i++) {
        int l;
        cin >> l;
        vector<int> temp(l + 1);
        for (int j = 1; j <= l; j++) {
            cin >> temp[j];
        }
        a[i] = temp;
    }
    int x, y;
    cin >> x >> y;
    cout << a[x][y] << endl;
    return 0;
}
