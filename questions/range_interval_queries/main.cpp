#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct FenwickTree {
	int n;
	vector<int> t;
	FenwickTree(int _n): n(_n + 1), t(_n + 2) {}
	void update(int pos, int delta) {
		for (pos++; pos < n; pos +=(-pos&pos)) {
			t[pos]+=delta;
		}
	}

	int query(int r) {
		int acc = 0;
		for (; r; r -= (-r&r)) {
			acc += t[r];
		}
		return acc;
	}

	inline int query(int l, int r) {
		return query(r + 1) - query(l);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<int> a(q), b(q), c(q), d(q);
	vector<vector<pair<int, int>>> pref(2 * n + 1);

	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--, b[i]--;
		if (a[i] != 0) {
			pref[a[i] - 1].emplace_back(c[i], d[i]);
		} else {
			pref[2 * n].emplace_back(c[i], d[i]);
		}
		pref[b[i]].emplace_back(c[i], d[i]);
	}


	vector<int> comp(begin(c), end(c));
	comp.insert(end(comp), begin(d), end(d));
	comp.insert(end(comp), begin(x), end(x));
	sort(begin(comp), end(comp));
	comp.erase(unique(begin(comp), end(comp)), end(comp));

	auto get_comp = [&](int val) -> int {
		return lower_bound(begin(comp), end(comp), val) - begin(comp); 
	};

	FenwickTree bit(comp.size() + 1);

	vector<tuple<int, int, int, int>> ans;
	for (auto &[ci, di]: pref[2 * n]) {
		ans.push_back(make_tuple(-1, ci, di, 0));
	}


	for (int i = 0; i < n; i++) {
		bit.update(get_comp(x[i]), 1);
		for (auto &[ci, di]: pref[i]) {
			int result = bit.query(get_comp(ci), get_comp(di));
			ans.push_back(make_tuple(i, ci, di, result));
		}
	}

	sort(begin(ans), end(ans));

	for (int i = 0; i < q; i++) {
		int r = get<3>(*lower_bound(begin(ans), end(ans), make_tuple(b[i], c[i], d[i], 0)));
		int l = get<3>(*lower_bound(begin(ans), end(ans), make_tuple(a[i] - 1, c[i], d[i], 0)));

		cout << r - l << endl;
	}






	return 0;
}
