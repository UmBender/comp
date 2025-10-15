#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> ad(n);
	for (auto &[a, d] : ad) { cin >> a >> d; }
	sort(ad.begin(), ad.end());
	int actual_moment = 0;
	int acc = 0;
	for (auto [a, d] : ad) {
		actual_moment += a;
		acc += d - actual_moment;
	}
	cout << acc << endl;
}
