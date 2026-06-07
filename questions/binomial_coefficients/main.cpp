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
#define int ll
mt19937 rng(random_device{}());

constexpr int MOD = 1e9 + 7;
constexpr int SIZE = (int)1e6 + 100;
int fact[SIZE], invFact[SIZE];

int inv(int a) {
    return a <= 1 ? a : MOD - (long long)(MOD / a) * inv(MOD % a) % MOD;
}

void setup() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    invFact[SIZE - 1] = inv(fact[SIZE - 1]);
    for (int i = SIZE - 2; i >= 1; i--) {
        invFact[i] = invFact[i + 1];
        invFact[i] *= (i + 1);
        invFact[i] %= MOD;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    setup();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int temp = fact[a] * invFact[b];
        temp %= MOD;
        temp *= invFact[a - b];
        temp %= MOD;
        cout << temp << endl;
    }

    return 0;
}
