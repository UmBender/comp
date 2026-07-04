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
		int x, y, k;
		cin >> x >> y >> k;
		int counter = 0;
		while (x != y) {
			if (x > y) {
				x /= k;
			} else {
				y /= k;
			}
			counter++;
		}
		cout << counter << endl;
	}

    return 0;
}
