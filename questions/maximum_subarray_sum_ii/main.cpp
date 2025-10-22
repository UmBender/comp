#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() { solution(); }
struct SegTree {
	vector<int> base;
	vector<int> tree;
	SegTree(vector<int> &b) : base(b), tree(b.size() * 4) {
		build(1, 0, b.size() - 1);
	}
	void build(int p, int tl, int tr) {
		if (tl == tr) {
			tree[p] = base[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(p * 2, tl, tm);
		build(p * 2 + 1, tm + 1, tr);
		tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
	}

	inline int query(int l, int r) {
		return query(1, 0, base.size() - 1, l, r);
	}

	int query(int p, int tl, int tr, int l, int r) {
		if (tl == l && tr == r) { return tree[p]; }
		if (r < tl || l > tr) { return (int)-1e18; }
		int tm = (tl + tr) / 2;
		int left = query(p * 2, tl, tm, l, min(r, tm));
		int right = query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return max(left, right);
	}
};
void solution() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n);
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + x[i]; }
	SegTree st(pref);
	int mmax = -1e18;
	for (int i = 0; i < n - a + 1; i++) {
		int actual = pref[i];
		int real_a = i + a;
		int real_b = min(i + b, n);
		int pmax = st.query(real_a, real_b);
		mmax = max(mmax, pmax - actual);
	}
	cout << mmax << endl;
}
