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
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> counter;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            counter[a[i]]++;
        }
        int unique;
        for (auto [k, v]: counter) {
            if (v == 1) {
                unique = k;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == unique) {
                cout << i + 1 << endl;
                break;
            }
        }

    }
    return 0;
}
