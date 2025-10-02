#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct BIT {
	vector<int> t;
	int n;
	BIT(int size) : t(size + 1), n(size) {
		for (int i = 0; i < n; i++) { update(i, 1); }
	}
	void update(int pos, int delta) {
		pos++;
		for (; pos <= n; pos += (-pos & pos)) { t[pos] += delta; }
	}

	int query(int left, int right) { return query(right) - query(left - 1); }
	int query(int right) {
		int acc = 0;
		right++;
		for (; right > 0; right -= (-right & right)) { acc += t[right]; }
		return acc;
	}
};

signed main() {
	int n, k;
	cin >> n >> k;
	BIT bit(n);
	set<int> n_used;
	auto succ = [&](int actual) -> int {
		int qq;
		if (actual == n - 1) {
			qq = 0;
		} else {
			qq = bit.query(actual + 1, n - 1);
		}
		int left, right;
		int beggin;
		if (qq != 0) {
			left = actual + 1, right = n - 1, beggin = actual + 1;
		} else {
			left = 0, right = n - 1, beggin = 0;
		}
		int pos = 0;

		while (left <= right) {
			int middle = (left + right) / 2;
			int qq = bit.query(beggin, middle);
			if (qq >= 1) {
				pos = middle;
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		return pos;
	};

	auto next_rem = [&](int actual) -> int {
		int in_range = bit.query(actual, n - 1);
		if (in_range >= k + 1) {
			int left = actual, right = n - 1;
			int pos = 0;
			while (left <= right) {
				int middle = (left + right) / 2;
				if (bit.query(actual, middle) >= k + 1) {
					pos = middle;
					right = middle - 1;
				} else {
					left = middle + 1;
				}
			}
			return pos;
		}
		int cost = k - in_range;
		int total = bit.query(0, n - 1);

		actual = succ(n - 1);
		int moves = cost % total;
		if (moves == 0) { return actual; }
		int left = actual + 1, right = n - 1;
		int pos = 0;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (bit.query(actual + 1, middle) >= moves) {
				pos = middle;
				right = middle - 1;

			} else {
				left = middle + 1;
			}
		}
		return pos;
	};
	for (int i = 0; i < n; i++) { n_used.insert(i); }
	int actual = 0;
	vector<int> ans;
	while (n_used.size() > 1) {
		int next_remove = next_rem(actual);
		bit.update(next_remove, -1);
		n_used.erase(next_remove);
		actual = succ(next_remove);
		ans.push_back(next_remove);
	}
	ans.push_back(*n_used.begin());
	for (int i = 0; i < n; i++) { cout << ans[i] + 1 << " "; }
	cout << endl;
}
