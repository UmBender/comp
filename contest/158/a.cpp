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
	int s[n];
	int wt[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		wt[i] = 0;
	}
	for (int j = 0; j < m; j++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		wt[a] += w;
		wt[b] += w;
	}
	int acc = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] > wt[i]) {
			acc++;
		}
	}
	cout << acc << endl;

    return 0;
}
