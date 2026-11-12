#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


struct FenwickTree {
	int n;
	vector<int> t;
	FenwickTree(int _n): n(_n + 1), t(_n + 1) {}

	void add(int pos, int delta) {
		for (pos++; pos < n; pos += -pos&pos) {
			t[pos] += delta;
		}
	}

	int query(int r) {
		int acc = 0;
		for (r++; r > 0; r -= -r&r) {
			acc += t[r];
		}
		return acc;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<int> bs = x;
	bs.push_back(-10);
	bs.push_back(1e9 + 10000);
	sort(begin(bs), end(bs));
	bs.erase(unique(begin(bs), end(bs)), end(bs));
	auto dec = [&](int val) -> int {
		return lower_bound(begin(bs), end(bs), val) - begin(bs);
	};

	FenwickTree cnt(bs.size()), sum(bs.size());

	auto median = [&]() -> int {
		int l = 0, r = bs.size() - 1;
		int ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			int acc = cnt.query(0, m);
			if (acc * 2 >= k) {
				ans = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return ans;
	};



	int left = 0, right = 0;
	vector<int> ans;
	map<int, int> cmp;
	cmp[-10] = 0;
	cmp[1e9 + 10000] = 0;


	while (right < n) {
		cnt.add(dec(x[right]), 1);
		sum.add(dec(x[right]), x[right]);
		cmp[dec(x[right])]++;
		right ++;
		if (right - left < k) {
			continue;
		}
		if (right - left > k) {
			cnt.add(dec(x[left]), -1);
			sum.add(dec(x[left]), -x[left]);
			cmp[dec(x[left])]--;
			if (cmp[dec(x[left])] == 0) {
				cmp.erase(dec(x[left]));
			}
			left ++;
		}

		int med = median();
		auto it = cmp.lower_bound(med);
		int actualMedian = bs[it->first];

		int upper = sum.query(it->first + 1, bs.size() - 1);
		int upperCnt = cnt.query(it->first + 1, bs.size() - 1);
		int upperCost = upper - actualMedian * upperCnt;

		int lower = sum.query(0, it->first - 1);
		int lowerCnt = cnt.query(0, it->first - 1);
		int lowerCost = actualMedian * lowerCnt - lower;
		ans.push_back(lowerCost+ upperCost);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return 0;
}
