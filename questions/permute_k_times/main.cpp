#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


struct BL {
	static constexpr int K = 64;
	int n;
	vector<array<int,K>> bl;

	BL(vector<int>& a): n(a.size()), bl(a.size()) {
		for (int i = 0; i < n; i++) {
			bl[i][0] = a[i];
		}
		build();
	}

	void build() {
		for (int i = 1; i < K; i++) {
			for (int j = 0; j < n; j++) {
				int temp = bl[j][i - 1];
				bl[j][i] = bl[temp][i - 1];
			}
		}
	}

	int query(int actual, int k) {
		int result = actual;
		for (int i = 0; i < 64; i++) {
			if ((k >> i) & 1) {
				result = bl[result][i];
			}
		}
		return result;
	}
};	

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> x(n), a(n);
	for (int& xi: x) {
		cin >> xi;
		xi--;
	}
	for (int& ai: a) {
		cin >> ai;
	}
	BL bl(x);
	vector<int> result(n);

	for (int i = 0; i < n; i++) {
		result[i] = a[bl.query(i, k)];
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " \n"[i == n - 1];
	}

	return 0;
}
