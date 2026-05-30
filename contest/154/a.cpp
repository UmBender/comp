#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define endl '\n'
#define int i64

signed main() {
    int n, m, c = 1;
    cin >> n >> m;


    while (n % m != 0) {
        c++;
        m = n % m;
    }
    cout << c << endl;

    return 0;
}
