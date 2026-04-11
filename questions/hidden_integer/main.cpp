#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

#define int i64

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    auto is_lower = [](int num) -> bool {
        cout << "? " << num << endl;
        cout.flush();
        string result;
        cin >> result;
        return result == "YES";
    };
    int left = 0, right = 1e9;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (is_lower(middle)) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << "! " << ((left + right) / 2) + 1 << endl;

    return 0;
}
