#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define endl '\n'
#define int i64

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

        int radius = r1 + r2;
        int diff = r1 - r2;

        if (diff * diff <= dist2 && dist2 <= radius * radius) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
