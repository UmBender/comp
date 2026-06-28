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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> x(n), y(n - 1);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n - 1;i ++) {
			cin >> y[i];
		}
		int dpS = (s[0] == 'S') ? 0: -x[0];
		int dpR = (s[0] == 'R') ? 0: -x[0];

		for (int i = 1; i < n; i++) {
			int costS = (s[i] == 'S') ? 0 : x[i];
			int costR = (s[i] == 'R') ? 0 : x[i];

			int nextS = max(dpS - costS, dpR - costS + y[i - 1]);
			int nextR = max(dpS - costR, dpR - costR);

			dpS = nextS;
			dpR = nextR;
		}
		cout << max(dpS, dpR) << endl;
	}

    return 0;
}
