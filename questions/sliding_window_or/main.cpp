#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using vl = vector<ll>;
using pll = pair<ll, ll>;
#define endl '\n'

struct Segtree {
	using S = int;
	const S e = 0;
	S op(S a, S b) { return a | b; }
	vector<S> t;
	int n;
	Segtree(int N): t(2 * N, e), n(N) {}
	void set(int i, S val) {
		t[i += n] = val;
		while (i >>= 1) t[i] = op(t[i << 1], t[i << 1 | 1]);
	}
	S query(int l, int r) {
		S al = e, ar = e;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) al = op(al, t[l++]);
			if (r & 1) ar = op(t[--r], ar);
		}
		return op(al, ar);
	}
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	Segtree seg(k);
	int pos = 1;
	ll all = 0;
	seg.set(0, x);
	
	while (pos < k) {
		x = (x * a + b);
		x %= c;
		seg.set(pos++, x);
	}
	pos = 0;
	all = seg.query(0, k);
	for (int i = k; i < n; i++) {
		x = (x * a + b);
		x %= c;
		seg.set(pos, x);
		all ^= seg.query(0, k);
		pos ++;
		pos %= k;
	}
	cout << all << endl;

	return 0;
}
