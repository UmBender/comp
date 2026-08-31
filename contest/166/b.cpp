#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> cnt(110);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cnt[temp]++;
	}
	int sum = 0;
	for (int i = 0; i < cnt.size(); i++) {
		sum += cnt[i] % 2 == 1 ? i : 0;
	}
	cout << sum << endl;
	return 0;
}
