#include <bits/stdc++.h>

using namespace std;

using i32 = int;
using i64 = long long;
#define int i64
#define all(x) x.begin(), x.end()


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int first = 0, second = 0;
        for (int i = 0; i < 3; i++) {
            first += s[i] - '0';
        }
        for (int i = 3; i < 6; i++) {
            second += s[i] - '0';
        }
        if (first == second) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
