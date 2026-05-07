#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    int a, b;
    cin >> a >> b;
    for (int bb = 0; bb <= b; bb++) {
        if (bb + a == 10) {
            cout << bb << " " << b - bb << endl;
        }
    }
    return 0;
}
