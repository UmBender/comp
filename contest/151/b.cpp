#include <bits/stdc++.h>
using namespace std;
using i32       = int;
using i64       = long long;
using i128      = __int128;
using VI        = vector<i32>;
using VVI       = vector<VI>;
using PII       = pair<i32, i32>;
using VII       = vector<PII>;
using VVII      = vector<VII>;
const int MAX_N = 100005;
int       dp[7][MAX_N][2];

i32 main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s = to_string(n);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < MAX_N; j++) {
            for (int l = 0; l < 2; l++) { dp[i][j][l] = -1; }
        }
    }

    function<int(int, int, bool)> rec;
    rec = [&](int i, int sum, bool low) {
        if (sum > k) { return 0; }

        if (i == s.size()) { return (sum == k) ? 1 : 0; }

        if (dp[i][sum][low] != -1) { return dp[i][sum][low]; }

        int limit = low ? 9 : (s[i] - '0');
        int count = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            bool new_low = low || (digit < limit);
            count += rec(i + 1, sum + digit, new_low);
        }
        dp[i][sum][low] = count;
        return dp[i][sum][low];
    };
    cout << rec(0, 0, false) << endl;
}
