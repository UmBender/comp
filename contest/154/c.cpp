#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define endl '\n'
#define int i64

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int counter = 0;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (b[j] <= a[i] * 2) {
            counter++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    cout << counter << endl;

    return 0;
}
