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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> diff((int)(1e6 + 5), 0);
    ll maxValid = 0;
    for (int i = 0; i < n; i++) {
        ll s, t;
        cin >> s >> t;
        ll l = s;
        ll r = t - d;
        if (l <= r) {
            diff[l]++;
            diff[r + 1]--;
            if (r > maxValid) {
                maxValid = r;
            }
        }
    }
    ll curr = 0, total = 0;
    for (int x = 1; x <= maxValid; x++) {
        curr += diff[x];
        if (curr >= 2) {
            total += (curr * (curr - 1)) / 2;
        }
    }
    cout << total << endl;

    return 0;
}
