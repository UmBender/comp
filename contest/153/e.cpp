#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

const int MOD = 998244353;
const int MAX = 3000005;
int fact[MAX];
int invFact[MAX];

int fast(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int modInv(int n) { return fast(n, MOD - 2); }

void precomp() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInv(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int comb(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }

    int up = fact[n] * invFact[r] % MOD;
    return (up * invFact[n - r]) % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    precomp();
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int ans = 0;
    int limit = min(x1, x2 + 1);
    for (int k = 0; k < limit; k++) {
        int w1 = comb(x2 + 1, k + 1);
        int w2 = comb(x1 - 1, k);
        int w3 = comb(x2 + x3 - k - 1, x3);

        int term = (w1 * w2) % MOD;
        term *= w3;
        term %= MOD;
        ans += term;
        ans %= MOD;
    }
    cout << ans << endl;
}
