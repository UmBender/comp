#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct BIT {
	int n;
	vector<int> tree;
	BIT(int N): n(N), tree(n + 1) {}
	int query(int left) {
		int acc = 0;
		left++;
		for (; left > 0; left -=(-left&left)) {
			acc += tree[left - 1];
		}
		return acc;
	}

	void update(int pos, int val) {
		pos++;
		for (; pos <= n; pos +=(-pos&pos)) {
			tree[pos - 1] += val;
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	map<int,int> comp, dec;
	{
		vector<int> xCopy = x;
		sort(xCopy.begin(), xCopy.end());
		for (int i = 0; i < xCopy.size(); i++) {
			comp[xCopy[i]] = i;
			dec[i] = xCopy[i];
		}
	}
	BIT bit(n + 1);

	auto bs = [&]() -> int {
		int l = 0, r = n - 1;
		int ans = r;
		while (l <= r) {
			int m = r + (l - r) / 2;
			int actual = bit.query(m);
			if (actual * 2 >= k) {
				ans = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return ans;
	};
	for (int i = 0; i < k; i++) {
		int actual = comp[x[i]];
		bit.update(actual, 1);
	}
	int ans = bs();
	cout << dec[ans] << " ";
	for (int i = k; i < n; i++) {
		int rem = comp[x[i - k]];
		bit.update(rem, -1);
		int actual = comp[x[i]];
		bit.update(actual, 1);
		int ans = bs();
		cout << dec[ans] << " ";
	}
	cout << endl;
}
