#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

template<class S, S (*op)(S, S), S (*e)()>
struct Segtree {
	vector<S> t;
	int n;
	Segtree(int N): t(2 * N, e()), n(N) {}
	void set(int i, S value) {
		t[i += n] = value;
		for (i >>= 1; i; i >>= 1) t[i] = op(t[i << 1], t[i << 1 | 1]);
	}
	S query(int l, int r) {
		S al = e(), ar = e();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) al = op(al, t[l++]);
			if (r & 1) ar = op(t[--r], ar);
		}
		return op(al, ar);
	}
	S get(int i) { return t[i + n]; }
};

mt19937 rng(random_device{}());
ll base = uniform_int_distribution<ll>(1, mod - 1)(rng);

struct H {
	ll v;
	int cnt;
	H(int x) : v(x + 10), cnt(1) {}
	H(): v(0), cnt(0) {}
	bool operator==(const H &other) const = default;
};

H op(H a, H b) {
	static vector<ll> pb = {1};
	while (a.cnt >= ssize(pb)) pb.push_back(base * pb.back() % mod);
	H ret;
	ret.cnt = a.cnt + b.cnt;
	ret.v = ((b.v * pb[a.cnt] % mod) + a.v) % mod;
	return ret;
}

H e() {
	return H{};
}

using Seg = Segtree<H, op, e>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = ssize(s);
	vector<int> d(n);
	{
		map<char, int> last;
		for (int i = n - 1; i >= 0; i--) {
			d[i] = max(0, last[s[i]] - i);
			last[s[i]] = i;
		}
	}
	Seg seg(n), suf(n);
	for (int i = 0; i < n; i++) {
		seg.set(i, H(0));
		suf.set(i, H(d[i]));
	}
	ll ans = 0;
	map<char, int> last;
	for (int i = 0; i < n - i - 1; i++) {
		if (last.count(s[i])) {
			seg.set(last[s[i]], H(d[last[s[i]]]));
		}
		if (seg.query(0, i + 1) == suf.query(n - i - 1, n)) {
			ans = i + 1;
		}
		last[s[i]] = i;
	}
	cout << ans << endl;
}
