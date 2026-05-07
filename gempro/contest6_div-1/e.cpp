#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    int neg = 0, zeros = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            neg ++;
        }
        if (s[i] == '0') {
            zeros = max(zeros, neg + 1ll);
        }
        if (s[i] == '+') {
            pos = max({pos + 1, zeros + 1, neg + 1});
        }
    }
    cout << max({pos, zeros, neg}) << endl;
}
