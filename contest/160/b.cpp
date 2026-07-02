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
constexpr int MAX_N = 1e5 + 100;
int a[MAX_N];
int n, t;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (t == 0) {
		cout << 0 << endl;
		return 0;
	}
	int mmin = 1e18;
	for (int i = 0; i < n; i++) {
		int temp = (a[i] + t - 1) / a[i];
		mmin = min(temp * a[i], mmin);
	}
	cout << mmin << endl;

    return 0;
}
