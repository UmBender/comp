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

struct BIT {
	int n;
	vector<int> t;
	BIT(int _n): n(_n + 1), t(_n + 2) {}
	void update(int l, int delta) {
		for (l++; l <= n; l += (-l&l)) {
			t[l] += delta;
		}
	}
	void update(int l, int r, int delta) {
		update(l, delta);
		update(r + 1, -delta);
	}

	int query(int pos) {
		int acc = 0;
		for (pos++; pos > 0; pos -= (-pos&pos)) {
			acc += t[pos];
		}
		return acc;
	}

};


int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	BIT bit(n);

	while (q--) {
		int l, r, c;
		cin >> l >> r >> c;
		bit.update(l, r, c);
	}

	for (int i = 1; i <= n;i++) {
		cout << bit.query(i) << " ";
	}
	cout << endl;

    return 0;
}
