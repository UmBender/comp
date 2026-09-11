#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


struct MergeSortTree {
	int n;
	vector<int> a;
	vector<vector<int>> tree;

	MergeSortTree(vector<int>& base): n(base.size()), a(begin(base), end(base)), tree(n * 4 + 50) {
		build(1, 0, n - 1);
	}
	void build(int tp, int tl, int tr) {
		if (tl > tr) {
			return;
		}
		if (tl == tr) {
			tree[tp] = {a[tl]};
			return;
		}
		int tm = tl + (tr - tl) / 2;
		build(tp * 2, tl, tm);
		build(tp * 2 + 1, tm + 1, tr);
		auto& first = tree[tp * 2];
		auto& second = tree[tp * 2 + 1];
		tree[tp].resize(first.size() + second.size());
		merge(begin(first), end(first), begin(second), end(second), begin(tree[tp]));
	}

	int query(int l, int r, int k) {
		return query(1, 0, n - 1, l, r, k);
	}

	int query(int tp, int tl, int tr, int l, int r, int k) {
		if (r < tl || l > tr) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			int temp = upper_bound(begin(tree[tp]), end(tree[tp]), k) - begin(tree[tp]);
			return temp;
		}
		int tm = tl + (tr - tl) / 2;
		return query(tp * 2, tl, tm, l, r, k) + 
			   query(tp * 2 + 1, tm + 1, tr, l, r, k);
	}


};

int main() {	
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	MergeSortTree mg(a);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		i--, j--;
		int l = -(1e9 + 100), r = 1e9 + 100;
		int sol = 1e9 + 100;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int actual = mg.query(i, j, m);
			if (k <= actual) {
				sol = min(sol, m);
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << sol << endl;
	}

	return 0;
}


