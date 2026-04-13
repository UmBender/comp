#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;

#define int i64

signed main() {
    int n;
    cin >> n;
    vector<int> p(n);
    auto build = [&](int period) -> string {
        string acc;

        for (int i = 0, j = 0, state = 0; i < n; i++, j++) {
            if(j == period) {
                j = 0;
                state = !state;
            }
            acc += state ? '1' : '0';
        }
        return acc;

    };
    auto query = [&](int period) {
        string builded = build(period);
        cout << "? " << builded << endl;
        cout.flush();
        string result;
        cin >> result;
        for (int i = 0; i < n; i++) {
            if (result[i] == '1') {
                p[i] += period;
            }
        }
    };

    for (int i = 1; i < (1 << 10); i <<= 1) {
        query(i);
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n-1];
    }

    return 0;
}
