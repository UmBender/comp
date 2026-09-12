#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int BLOCK = 400;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int numBlock = (n + BLOCK - 1) / BLOCK;
	vector<vector<int>> blocks(numBlock);

	for (int i = 0; i < n; i++) {
		blocks[i / BLOCK].push_back(a[i]);
	}

	for (int i = 0; i < numBlock; i++) {
		sort(begin(blocks[i]), end(blocks[i]));
	}



	int q;
	cin >> q;


	auto firstOp = [&](int l, int r, int x) -> int {
		l--, r--;
		x--;
		int ans = 0;
		int bLeft = l / BLOCK;
		int bRight = r / BLOCK;
		if (bLeft == bRight) {
			for (int i = l; i <= r; i++) {
				if (a[i] <= x) ans++;
			}
		} else {
			int endLeft = (bLeft + 1) * BLOCK;
			for (int i = l; i < endLeft; i++) {
				if (a[i] <= x) ans++;
			}
			for (int b = bLeft + 1; b < bRight; b++) {
				ans += upper_bound(begin(blocks[b]), end(blocks[b]), x) - begin(blocks[b]);
			}
			int startRight = bRight * BLOCK;
			for (int i = startRight; i <= r; i++) {
				if (a[i] <= x) ans++;
			}
		}
		return (r - l + 1) - ans;
	};

	auto secondOp = [&](int pos, int val) {
		pos--;
		int bIndex = pos / BLOCK;
		int oldVal = a[pos];
		a[pos] = val;

		auto it = lower_bound(begin(blocks[bIndex]), end(blocks[bIndex]), oldVal);
		blocks[bIndex].erase(it);
		auto it2 = upper_bound(begin(blocks[bIndex]), end(blocks[bIndex]), val);
		blocks[bIndex].insert(it2, val);
	};

	while (q--) {
		int opt;
		cin >> opt;
		if (!opt) {
			int l, r, x;
			cin >> l >> r >> x;
			cout << firstOp(l, r, x) << endl;
		} else {
			int pos, val;
			cin >> pos >> val;
			secondOp(pos, val);
		}
	}

	return 0;
}




