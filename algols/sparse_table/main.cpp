#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

auto f(int a, int b) -> int { return min(a, b); }
struct SparseTable {
	static const int K = 25;
	static const int MAXN = 1E3;
	int st[K + 1][MAXN];
	int n;
	SparseTable(vector<int> &array) : n(array.size()) {
		copy(array.begin(), array.end(), st[0]);
		for (int i = 1; i <= K; i++) {
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int left, int right) {
		int acc = 1e8;
		for (int i = K; i >= 0; i--) {
			if ((1 << i) <= right - left + 1) {
				acc = f(acc, st[i][left]);
				left += 1 << i;
			}
		}
		return acc;
	}
};

void solution() {
	vector<int> inputs = {1, 2, 3, 4, 5};
	SparseTable st(inputs);
	cout << "Okay" << endl;
	cout << st.query(1, 3) << endl;
}

int32_t main() {
	solution();
	return 0;
}
