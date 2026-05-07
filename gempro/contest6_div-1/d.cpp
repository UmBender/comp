#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "No" << endl;
        return 0;
    }
    if (n % 2 == 1) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        return 0;
    }

    vector<int> vals;
    vals.push_back(1);
    for (int i = 3; i <= n; i++) {
        vals.push_back(i);
    }
    vals.push_back(2);
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << vals[i] << " ";
    }
    cout << endl;

    return 0;
}
