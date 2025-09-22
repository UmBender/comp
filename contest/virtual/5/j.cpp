#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
struct BIT {
	vector<int> tree;
	vector<int> base;
	int ssize;
	BIT(int size) : tree(size + 1), base(size), ssize(size) {}
	void update(int pos, int value) {
		int delta = value ^ base[pos];
		base[pos] = value;
		pos++;
		for (; pos <= ssize; pos += (-pos & pos)) { tree[pos] ^= delta; }
	}
	inline int query(int left, int right) {
		return query(right) ^ query(left - 1);
	}
	int query(int right) {
		int acc = 0;
		right++;
		for (; right > 0; right -= (-right & right)) { acc ^= tree[right]; }
		return acc;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> b(n);
	for (auto &i : b) { cin >> i; }
	BIT changes(n);
	for (int i = 0; i < n; i++) { changes.update(i, b[i]); }

	while (q--) {
		char opt;
		cin >> opt;
		if (opt == 'P') {
			int left, right;
			cin >> left >> right;
			left--, right--;
			// cout << "L,R: " << left << " " << right << endl;
			// cout << "CHANGE: " << change << endl;
			if (changes.query(left, right)) {
				cout << "FRANK" << endl;
			} else {
				cout << "JUAN" << endl;
			}

		} else {
			int pos, x;
			cin >> pos >> x;
			pos--;
			int result = b[pos] + x;
			b[pos] = result;
			changes.update(pos, b[pos]);
		}
	}

	return 0;
}
