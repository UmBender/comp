#include <bits/stdc++.h>

using namespace std;

using i32 = int;
using i64 = long long;
#define int i64
#define all(x) x.begin(), x.end()

#define endl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }


    vector<array<int, 33>> binary_lifting(n + 1);
    for (int i = 1; i <= n; i++) {
        binary_lifting[i][0] = t[i];
    }
    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= n; j++) {
            int first = binary_lifting[j][i - 1];
            int second = binary_lifting[first][i - 1];
            binary_lifting[j][i] = second;
        }
    }

    auto calc = [&](int x, int k) -> int {
        int actual = x;
        for (int i = 0; i <= 32; i++) {
            int value = 1ll << i;
            if (value & k) {
                actual = binary_lifting[actual][i];
            }
        }
        return actual;

    };

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        cout << calc(x, k) << endl;
    }

    return 0;
}
