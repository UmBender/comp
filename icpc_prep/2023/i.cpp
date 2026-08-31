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

#define int ll
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> b(n);
	for (int &bi: b) cin >> bi;
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + b[i];
	}
	int evens = 0, odds = 0;
	for (int i = n; i > 0; i--) {
		if (pref[i] % 2 == 0) {
			evens++;
		} else {
			odds++;
		}
	}
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		if (pref[i - 1] % 2 == 0) {
			counter += odds;
		} else {
			counter += evens;
		}
		if (pref[i] % 2 == 0) {
			evens--;
		} else {
			odds--;
		}
	}

	cout << counter << endl;



	return 0;
}

