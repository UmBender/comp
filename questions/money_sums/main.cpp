#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
const int MAX_SUM = 100 * 1000;
void solution() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	ranges::sort(x);
	vector<int> all_sum(1000 * 100 + 10);
	all_sum[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = MAX_SUM; j >= 0; j--) {
			if (all_sum[j]) { all_sum[j + x[i]] = 1; }
		}
	}
	vector<int> vals;
	for (int i = 1; i <= MAX_SUM; i++) {
		if (all_sum[i]) { vals.push_back(i); }
	}
	cout << vals.size() << endl;
	int nn = vals.size() - 1;
	for (int i = 0; i <= nn; i++) { cout << vals[i] << " \n"[i == nn]; }
}
