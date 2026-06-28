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


template<class S, S(*op)(S, S), S(*e)()>
struct Segtree {
	vector<S>t;
	int n;
	Segtree(int N): t(2 * N, e()), n(N) {}
	void set(int i, S value) {
		t[i += n] = value;
		for (i >>= 1; i; i>>=1) t[i] = op(t[i << 1], t[i << 1 | 1]);
	}
	S query(int l, int r) {
		S al = e(), ar = e();
		for (l += n, r += n; l < r; l >>=1, r>>=1) {
			if (l&1) al = op(al, t[l++]);
			if (r&1) ar = op(t[--r], ar);
		}
		return op(al, ar);
	}
};

int minE() {
	return 1e9 + 100;
}

int minOp(int a, int b) {
	return min(a, b);
}

int sumE() {
	return 0;
}

int sumOp(int a, int b) {
	return a + b;
}

using MinSeg = Segtree<int, minOp, minE>;
using SumSeg = Segtree<int, sumOp, sumE>;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, w, k;
	cin >> n >> w >> k;
	vector<int> a(n);
	MinSeg mmin(n);
	SumSeg sum(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mmin.set(i, a[i]);
		sum.set(i, a[i]);
	}
	vector<int> ans;
	for (int i = 0; i + w <= n; i++) {
		ans.push_back(sum.query(i, i + w) + k * mmin.query(i, i + w));
	}	
	cout << *max_element(all(ans)) << endl;
    return 0;
}
