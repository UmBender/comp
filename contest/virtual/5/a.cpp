#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) { cin >> i; }
	ll acc = 0;
	for (int i = 0; i < n; i++) { acc += a[i]; }
	ll pseudon = n;
	while (pseudon > 1) {
		if (acc % pseudon == 0) { break; }
		pseudon--;
	}
	cout << n - pseudon << endl;

	return 0;
}
