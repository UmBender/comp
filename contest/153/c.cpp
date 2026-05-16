#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    string s;
    cin >> s;
    int left = 0, right = s.size() - 1;
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            int all = min(left, right);
            counter += all + 1;
        }
        left++;
        right--;
    }
    cout << counter << endl;
}
