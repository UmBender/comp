#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define int i64


signed main() {
    auto calc = [](int n) -> int {
        int total = n * n;
        int acc = (total) * (total - 1) / 2;
        int remove_hor = 2 * (n - 2) * (n - 1);
        int remove_ver = 2 * (n - 1) * (n - 2);
        acc -= remove_hor;
        acc -= remove_ver;
        return acc;
    };

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << calc(i) << endl;
    }

    return 0;
}

