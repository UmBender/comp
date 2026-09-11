#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct MergeSortTree {
	int n;
	vector<int> a;
	vector<vector<int>> t;
	MergeSortTree(vector<int>& base): n(base.size()), a(begin(base), end(base)), t(4 * n + 10) {
		build(1, 0, n - 1);
	}

	void build(int tp, int tl, int tr) {
		if (tl == tr) {
			t[tp] = {a[tl]};
			return;
		}
		int tm = (tl + tr) / 2;
		build(tp * 2, tl, tm);
		build(tp * 2 + 1, tm + 1, tr);
		t[tp].resize(t[tp * 2].size() + t[tp * 2 + 1].size());
		merge(begin(t[tp * 2 ]), end(t[tp * 2]), begin(t[tp * 2 + 1]), end(t[tp * 2 + 1]), begin(t[tp]));
	}

	int query(int l, int r, int k) {
		return query(1, 0, n - 1, l, r, k);
	}

	int query(int tp, int tl, int tr, int l, int r, int k) {
		if (l > tr || r < tl) return 0;
		if (l <= tl && tr <= r) {
			int temp = upper_bound(begin(t[tp]), end(t[tp]), k) - begin(t[tp]);
			return temp;
		}

		int tm = (tl + tr) / 2;

		return query(tp * 2, tl, tm, l, r, k) + query(tp * 2 + 1, tm + 1, tr, l, r, k);
	}
};

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int q;
	cin >> q;

	MergeSortTree mg(a);

	while (q--) {
		int i, j, k;
		cin >> i >> j >> k;
		i--, j--;
		cout << (j - i + 1) - mg.query(i, j, k) << endl;
	}

	return 0;
}
