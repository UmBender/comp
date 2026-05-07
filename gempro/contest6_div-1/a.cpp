#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;
    if (a * c + b * d > s ) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;


    return 0;
}
