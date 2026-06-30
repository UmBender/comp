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
	int n, m;
	cin >> n >> m;
	vector<int> r(n), s(m);
	for (int &i: r) {
		cin >> i;
	}
	for (int &i: s) {
		cin >> i;
	}
	int mmin = s.front();
	for (int i = 1; i < m; i++) {
		mmin = min(mmin, s[i]);
	}
	sort(all(r));
   int counter = upper_bound(all(r), mmin) - r.begin();
	cout << counter << endl;
    return 0;
}
