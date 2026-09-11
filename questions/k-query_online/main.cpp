#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


struct MergeSortTree {
	int n;
	vector<int> a;
	vector<vector<int>> tree;

	MergeSortTree(vector<int>& base): n(base.size()), a(begin(base), end(base)), tree(4 * n + 50) {
		build(1, 0, n - 1);
	}

	void build(int tp, int tl, int tr) {
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
		if (l > tr || r < tl) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			int temp = upper_bound(begin(tree[tp]), end(tree[tp]), k) - begin(tree[tp]);
			return temp;
		}

		int tm = tl + (tr - tl) / 2;
		return query(tp * 2, tl, tm, l, r, k) + query(tp * 2 + 1, tm + 1, tr, l, r, k);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	MergeSortTree mg(a);
	int q;
	cin >> q;
	int last = 0;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		int i = a ^ last, j = b ^ last, k = c ^ last;
		i = max(i, 1);
		j = min(j, n);
		i--, j--;
		if (i > j) {
			last = 0;
		} else {
			int temp = mg.query(i, j, k);
			last = (j - i + 1) -  temp;
		}
		cout << last << endl;
	}
}


