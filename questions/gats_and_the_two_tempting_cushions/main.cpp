#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

constexpr int LOG = 61;

struct BL {
	vector<array<int, LOG>> bl;
	vector<array<int, LOG>> sum;
	int n;
	BL(vector<int> &a, vector<int>& counter): bl(a.size()), n(a.size()), sum(a.size()) {
		for (int i = 0; i < n; i++) {
			bl[i][0] = a[i];
			sum[i][0] = counter[i];
		}
		build();
	}

	void build() {
		for (int p = 1; p < LOG; p++) {
			for (int i = 0; i < n; i++) {
				int one = bl[i][p - 1];
				int two = bl[one][p - 1];
				bl[i][p] = two;

				int acc = sum[i][p - 1];
				acc += sum[one][p - 1];

				sum[i][p] = acc;
			}
		}
	}

	pair<int,int> query(int in, int jumps) {
		int actual = in;
		int acc = 0;
		for (int p = LOG - 1; p >= 0; p--) {
			int pp  = jumps >> p;
			if (pp & 1) {
				acc += sum[actual][p];
				actual = bl[actual][p];
			}
		}
		return {actual, acc};
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);

	for (int& ai: a) {
		cin >> ai;
	}

	vector<int> nextLower(n), nextBigger(n);
	vector<int> lowers, biggers;
	for (int i = n - 1; i >= 0; i--) {
		nextLower[i] = i;
		nextBigger[i] = i;
		while (!lowers.empty() && a[lowers.back()]  >= a[i]) {
			lowers.pop_back();
		}	
		if (!lowers.empty()) {
			nextLower[i] = lowers.back();
		}
		lowers.push_back(i);

		while (!biggers.empty() && a[biggers.back()] <= a[i]) {
			biggers.pop_back();
		}
		if (!biggers.empty()) {
			nextBigger[i] = biggers.back();
		}
		biggers.push_back(i);
	}

	vector<int> next(n);
	vector<int> counter(n);
	for (int i = 0; i < n; i++) {
		int bigger = 2e18, biggerPos = i;
		int lower = 2e18, lowerPos = i;

		if (nextLower[i] != i) {
			lowerPos = nextLower[i];
			lower = abs(a[lowerPos] - a[i]);
		}

		if (nextBigger[i] != i) {
			biggerPos = nextBigger[i];
			bigger = abs(a[biggerPos] - a[i]);
		}

		if (bigger == lower) {
			if (biggerPos < lowerPos) {
				next[i] = biggerPos;
				counter[i] = 1;
			} else {
				next[i] = lowerPos;
			}

		} else if (bigger < lower) {
			next[i] = biggerPos;
			counter[i] = 1;
		} else {
			next[i] = lowerPos;
		}
	}


	BL bl(next, counter);
	for (int qq = 0; qq < q; qq++) {
		int x, k;
		cin >> x >> k;	
		pair<int,int> result = bl.query(x - 1, k);
		cout << result.first + 1 << " " << result.second << endl;
	}



	return 0;
}
