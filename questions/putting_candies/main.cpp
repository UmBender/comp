#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


struct BL {
	static constexpr int K = 41;
	int n;
	vector<array<int,K>> bl;
	BL(vector<int>& a): bl(a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) {
			bl[i][0] = a[i];
		}
		build();
	}

	void build() {
		for (int k = 1; k < K; k++) {
			for (int i = 0; i < n; i++) {
				int sum = 0;
				sum += bl[i][k - 1];
				sum += bl[(i + sum) % n][k - 1];
				bl[i][k] = sum;
			}
		}
	}

	int query(int k) {
		int sum = 0;
		for (int i = 0; i < K; i++) {
			if ((k >> i) & 1) {
				sum += bl[sum % n][i];
			}
		}
		return sum;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& ai: a) cin >> ai;
	BL bl(a);
	cout << bl.query(k) << endl;

	return 0;
}
