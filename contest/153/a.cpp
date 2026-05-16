#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    string s;
    int n;
    cin >> s >> n;
    cout << s.substr(n, s.size() - 2 * n) << endl;
}
