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
	int x, y, l, r, a, b;
	cin >> x >> y >> l >> r >> a >> b;

	vector<int> lr(24);
	for (int i = 1; i <= 23; i++) {
		if (i >= l && i < r) {
			lr[i] = x;
		} else {
			lr[i] = y;
		}
	}
	int acc = 0;
	for (int i = a; i < b; i++) {
		acc += lr[i];
	}
	cout << acc << endl;
    return 0;
}
