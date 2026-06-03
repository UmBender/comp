#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {

    auto calc = [&](int pos) -> int {
        if (pos <= 9) {
            return pos; 
        }
        int digits = 2;
        int last = 10;
        int numDigits = (9 * last) * digits;
        pos -= 9;
        while (pos > numDigits) {
            pos -= numDigits;
            last *= 10;
            digits++;
            numDigits = (9 * last) * digits;
        }
        pos--;
        int actual_number = (pos / digits) + last;
        int rest = pos % digits;
        cerr << "actual_number: " << actual_number << endl;
        return (to_string(actual_number)[rest] - '0');
    };
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int result = calc(k);
        cout << result << endl;
    }
    return 0;
}
