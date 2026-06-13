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


ll even(ll x, ll y, ll a,ll b) {
    ll m = abs(x + y) / 2;
    ll n = abs(x - y) / 2;
    ll mmax = max(m, n);
    ll mmin = min(m, n);
    ll diag = min(2 * a, 2 * b);
    ll one = mmin * (a + b) + (mmax - mmin) * diag;
    ll two = (mmax + mmin) * diag;
    return min(one, two);
}
void solution() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (abs(x + y) % 2 == 0) {
        cout << even(x, y, a, b) << endl;
    } else {
        ll mmin = min({
            even(x - 1, y, a, b) + a,
            even(x + 1, y, a, b) + a,
            even(x, y - 1, a, b) + b,
            even(x, y + 1, a, b) + b,
        });
        cout << mmin << endl;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
