#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    int q;
    cin >> q;
    vector<int> values;

    auto one = [&]() {
        int m, k;
        cin >> m >> k;
        if (k % 2 == 0) {
            values.push_back(0);
            return;
        }
        values.push_back(m);
    };

    auto second = [&]() {
        int first, second;
        cin >> first >> second;
        first--, second--;
        values.push_back(values[first] ^ values[second]);
    };

    auto third = [&]() {
        int pos, val, times;
        cin >> pos >> val >> times;
        pos--;
        int new_value = values[pos];
        if (times % 2 != 0) {
            new_value ^= val;
        }
        values.push_back(new_value);
    };

    auto fourth = [&]() -> int {
        int pos;
        cin >> pos;
        pos--;
        return values[pos];
    };

    for (int i = 0; i < q; i++) {
        int input;
        cin >> input;
        switch (input) {
        case 1:
            one();
            break;
        case 2:
            second();
            break;
        case 3:
            third();
            break;
        case 4:
            cout << fourth() << endl;
        }
    }
    return 0;
}
