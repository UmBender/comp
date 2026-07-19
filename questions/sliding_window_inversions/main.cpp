#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

struct BIT {
	int n;
	vector<int> t;
	BIT (int N): n(N), t(N + 1) {}
	void update(int pos, int delta) {
		pos++;
		for (;pos <= n; pos+=(-pos&pos)) {
			t[pos-1] += delta;
		}
	}
	int query(int left) {
		int acc = 0;
		left ++;
		for (; left > 0; left -=(-left&left)) {
			acc += t[left - 1];
		}
		return acc;
	}
	
	inline int query(int left, int right) {
		return query(right) - query(left - 1);
	}
};


signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	map<int, int> comp, dec;
	{
		vector<int> xCopy = x;
		sort(xCopy.begin(), xCopy.end());
		for (int i = 0; i < n; i++) {
			comp[xCopy[i]] = i;
			dec[i] = xCopy[i];
		}
	}

	int inversions = 0;
	BIT bit(n + 1);
	for (int i = 0; i < k; i++) {
		int actual = comp[x[i]];
		inversions += bit.query(actual + 1, n - 1);
		bit.update(actual, 1);
	}
	vector<int> ans;
	ans.push_back(inversions);

	for (int i = k; i < n; i++) {
		int last = comp[x[i - k]];
		int rem = bit.query(0, last - 1);
		inversions -= rem;
		bit.update(last, -1);

		int front = comp[x[i]];
		int add = bit.query(front + 1, n - 1);
		inversions += add;
		bit.update(front, 1);

		ans.push_back(inversions);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}


	return 0;
}
