#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i >= n / 2) {
			sum += temp;
		}
	}
	cout << sum << endl;
	return 0;
}
