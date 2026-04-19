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
        string s;
        cin >> n;
        cin >> s;
        set<char> c;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!c.count(s[i])) {
                counter++;
            }
            counter++;
            c.insert(s[i]);
        }
        cout << counter << endl;
    }
    return 0;
}
