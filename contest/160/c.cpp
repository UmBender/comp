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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    int minA = a[0];
    int maxA = a[n - 1];

    bool poss = true;
    for (int i = 0; i < m; i++) {
        if (b[i] > minA && b[i] < maxA) {
            poss = false;
            break;
        }
    }

    if (!poss) {
        cout << -1 << endl;
        return 0;
    }

    int med = a[n / 2];
    int total = 0;

    for (int i = 0; i < n; ++i) {
        total += abs(a[i] - med);
    }

    cout << total << endl;

    return 0;
}
