#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); i++)


const ll mod = 1e9 + 7;

ll powm(ll x, ll e) {
	ll r = 1;
	while (e) {
		if (e & 1) (r *= x) %= mod;
		(x *= x) %= mod;
		e >>= 1;
	}
	return r;
}


int gauss(vector<vector<ll>> &a) {
	int n = sz(a), m = sz(a[0]), r = 0;
	rep(c,0,m) {
		int p = r;
		while (p < n && !a[p][c])p++;
		if (p == n) continue;
		swap(a[p], a[r]);
		ll iv = powm((a[r][c] % mod + mod) % mod, mod - 2);
		rep(j,c,m) a[r][j] = a[r][j] * iv % mod;
		rep(i,0,n) if (i != r && a[i][c]) {
			ll x = a[i][c];
			rep(j,c,m) a[i][j] = (a[i][j] - x * a[r][j]) % mod;
		}
		r++;
	}
	rep(i,0,n) rep(j,0,m) if (a[i][j] < 0) a[i][j] += mod;
	return r;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vvi sys(n, vi(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			cin >> sys[i][j];
		}
	}
	gauss(sys);

	bool isValid = true;
	bool inde = false;
	map<vi, int> byRes;
	for (int i = 0; i < n; i++) {
		vi actual(begin(sys[i]), end(sys[i]) - 1);
		if (byRes.count(actual)) {
			if (byRes[sys[i]] != sys[i][m]) {
				isValid = false;
				break;
			}
		} else {
			byRes[actual] = sys[i][m];
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			if (actual[i] == 0) cnt++;
		}
		if (cnt == m && sys[i][m] != 0) {
			inde = true;
			isValid = false;
			break;
		}
	}
	if (!isValid) {
		cout << -1 << endl;
		return 0;
	}	

	map<int, int> ans;
	int r = 0;
	for (int i = 0; i < n; i++) {
		while (sys[i][r] == 0 && r < m) {
			r++;
		}
		ans[r] = sys[i][m];
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}
