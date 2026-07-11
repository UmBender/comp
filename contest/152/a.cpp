#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cout << a[x] << endl;

    return 0;
}
