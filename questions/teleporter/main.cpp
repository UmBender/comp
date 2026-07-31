#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

struct BL {
	static constexpr int K = 64;
	int n;
	vector<array<int, K>> bl;
	BL(vector<int>& a): bl(a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) {
			bl[i][0] = a[i];
		}
		build();
	}

	void build() {
		for (int h = 1; h < K; h++) {
			for (int i = 0; i < n; i++) {
				int temp = bl[i][h - 1];
				bl[i][h] = bl[temp][h - 1];
			}
		}
	}

	int query(int k, int actual) {
		int pos = actual;
		for (int i = 0; i < K; i++) {
			if ((k >> i) & 1) {
				pos = bl[pos][i];
			}
		}
		return pos;
	}
};


signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& ai: a) {
		cin >> ai;
		ai--;
	}
	BL bl(a);
	cout << bl.query(k, 0) + 1 << endl;
	return 0;
}
