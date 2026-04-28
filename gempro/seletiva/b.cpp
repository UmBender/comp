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
        if (n == 2) {
            cout << "01" << endl;
            continue;
        }
        cout << "1";
        for (int i = 1; i < n - 1;i ++) {
            cout << "0";
        }
        cout << "1" << endl;
    }
    
    return 0;
}
