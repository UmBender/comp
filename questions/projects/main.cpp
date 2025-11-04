#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() { solution(); }

struct SegTree {
	vector<int> tree;
	vector<int> base;
	SegTree(int size) : tree(size * 4), base(size) {}
	int query(int left, int right) {
		return query(1, 0, base.size() - 1, left, right);
	}

	int query(int pos, int tl, int tr, int l, int r) {
		if (tl == l && tr == r) { return tree[pos]; }
		if (tl > r || l > tr) { return 0; }
		int tm = (tl + tr) / 2;
		int left = query(pos * 2, tl, tm, l, min(tm, r));
		int right = query(pos * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
		return max(left, right);
	}

	void update(int pos, int val) { update(1, 0, base.size() - 1, pos, val); }
	void update(int p, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			tree[p] = max(tree[p], val);
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {

			update(p * 2, tl, tm, pos, val);
		} else {
			update(p * 2 + 1, tm + 1, tr, pos, val);
		}
		tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
	}
};
void solution() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> abp(n);
	vector<int> nums;
	for (auto &[a, b, p] : abp) {
		cin >> a >> b >> p;
		nums.push_back(a);
		nums.push_back(b);
	}
	ranges::sort(nums);
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	ranges::sort(abp);
	ranges::reverse(abp);
	int actual{0};
	map<int, int> comp;
	for (auto i : nums) {
		comp[i] = actual;
		actual++;
	}
	SegTree st(nums.size() + 1);
	for (int i = 0; i < n; i++) {
		auto [a, b, p] = abp[i];
		int mmax = st.query(comp[b] + 1, nums.size());
		st.update(comp[a], mmax + p);
	}
	cout << st.query(0, nums.size()) << endl;
}
