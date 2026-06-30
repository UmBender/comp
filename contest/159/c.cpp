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
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(0);
    int n, s, k;
    cin >> n >> s >> k;
    s--;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int mmax = 0;
    for (int x = 0; x <= s; x++) {
        if (2 * x <= k) {
            int y = min(n - 1 - s, k - 2 * x);
            mmax = max(mmax, pref[s + y + 1] - pref[s - x]);
        }
    }

    for (int y = 0; y <= n - 1 - s; y++) {
        if (2 * y <= k) {
            int x = min(s, k - 2 * y);
            mmax = max(mmax, pref[s + y + 1] - pref[s - x]);
        }
    }

    cout << mmax << endl;

    return 0;
}
