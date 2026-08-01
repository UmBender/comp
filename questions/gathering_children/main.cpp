#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


struct BL {
	static constexpr int K = 18;
	vector<array<int,K>> bl;
	int n;

	BL(vector<int>& p): n(p.size()), bl(p.size()) {
		for (int i = 0; i < n; i++) {
			bl[i][0] = p[i];
		}
		build();
	}

	void build() {
		for (int k = 1; k < K; k++) {
			for (int i = 0; i < n; i++) {
				int temp = bl[i][k - 1];
				bl[i][k] = bl[temp][k - 1];
			}
		}
	}

	int query(int actual, int k) {
		int ans = actual;
		for (int i = 0; i < K; i++) {
			if ((k >> i) & 1) {
				ans = bl[ans][i];
			}
		}
		return ans;
	}
};



signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			a[i] = i - 1;
		} else {
			a[i] = i + 1;
		}
	}
	BL bl(a);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[bl.query(i, 100'000)]++;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}
