#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> cnt(k);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		tmp--;
		cnt[tmp]++;
	}
	int mmax = 0;
	for (int i = 0; i < k; i++) {
		mmax = max(mmax, cnt[i]);
	}
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (cnt[i] == mmax) count++;
		if (cnt[i] == mmax - 1) count++;
	}
	cout << count << endl;

	return 0;
}
