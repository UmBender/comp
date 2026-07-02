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

    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    int off = n + 5;
    int mmax = 3 * n + 15;

    vector<int> d2(mmax, 0);

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;

        int l = p - b + 1;
        int m = p + 1;
        int r = p + b + 1;

        d2[l + off] += 1;
        d2[m + off] -= 2;
        d2[r + off] += 1;
    }

    vector<int> d1(mmax, 0);
    vector<int> s(mmax, 0);

    d1[0] = d2[0];
    s[0] = d1[0];

    for (int i = 1; i < mmax; i++) {
        d1[i] = d1[i - 1] + d2[i]; 
        s[i] = s[i - 1] + d1[i];  
    }

    int mmaxS = -1;
    for (int i = 1; i <= n; i++) {
        int curr = s[i + off];
        if (curr <= t[i]) {
            mmaxS = max(mmaxS, curr);
        }
    }

    cout << mmaxS << endl;
    return 0;
}
