#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

const int MOD = 998244353;

string n;
int dp[505][3][2][1024];

int solve(int i, bool noZero, int rem3, bool has3, int nums) {
    if (i == n.length()) {
        if (nums == 0) {
            return 0;
        }
        int cnt = (rem3 == 0) + has3 + (__builtin_popcount(nums) == 3);
        return cnt == 1 ? 1 : 0;
    }

    if (!noZero && dp[i][rem3][has3][nums] != -1) {
        return dp[i][rem3][has3][nums];
    }

    int limit = noZero ? (n[i] - '0') : 9;
    int ans = 0;

    for (int d = 0; d <= limit; d++) {
        bool ntight = noZero && (d == limit);
        int nNums = nums, nrem3 = rem3;
        bool nhas3 = has3;

        if (nums != 0 || d != 0) {
            nNums |= (1 << d);
            nrem3 = (rem3 + d) % 3;
            nhas3 |= (d == 3);
        }

        ans += solve(i + 1, ntight, nrem3, nhas3, nNums);
        ans %= MOD;
    }

    if (!noZero) {
        dp[i][rem3][has3][nums] = ans;
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < 505; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 1024; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    cout << solve(0, true, 0, false, 0) << endl;

    return 0;
}
