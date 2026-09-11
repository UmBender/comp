#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;


struct MergeSortTree {
	int n;
	vector<vector<int>> tree;
	MergeSortTree(vector<int>& base): n(base.size()), tree(4 * n + 50) {
		build(1, 0, n - 1, base);
	}
	void build(int tp, int tl, int tr, vector<int>& a) {
		if (tr < tl) {
			return;
		}
		if (tl == tr) {
			tree[tp] = {a[tl]};
			return;
		}
		int tm = tl + (tr - tl) / 2;
		build(2 * tp, tl, tm, a);
		build(2 * tp + 1, tm + 1, tr, a);
		auto& first = tree[2 * tp];
		auto& second = tree[2 * tp + 1];
		tree[tp].resize(first.size() + second.size());

		merge(begin(first), end(first), begin(second), end(second), begin(tree[tp]));
	}
	int query(int l, int r, int k) {
		return query(1, 0, n - 1, l, r, k);
	}

	int query(int tp, int tl, int tr, int l, int r, int k) {
		if (tl > r || tr < l) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			int temp = lower_bound(begin(tree[tp]), end(tree[tp]), k) - begin(tree[tp]);
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
	vector<int> pref1(n), pref2(n);
	{
		map<int, int> count1, count2;
		for (int i = 0; i < n; i++) {
			count1[a[i]]++;
			pref1[i] = count1[a[i]];
		}	
		for (int i = n - 1; i >= 0; i--) {
			count2[a[i]]++;
			pref2[i] = count2[a[i]];
		}
	}
	

	MergeSortTree mg(pref2);
	ll acc = 0;
	for (int i = 0; i < n - 1; i++) {
		ll actual = pref1[i];
		ll result = mg.query(i + 1, n - 1, actual);
		acc += result;
	}

	cout << acc << endl;

	return 0;
}
