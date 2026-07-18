#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> x(n);
	vector<ll> h(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	auto check = [&](ll mmax) -> bool {
		ll i = 0;
		ll maxValue = 0;
		ll begin = x[0];
		ll end = 0;
		ll div = 1;
		
		
		while (i < n) {
			end = x[i];
			maxValue = max(maxValue, h[i]);
			ll actual = maxValue + (end - begin);

			if (actual > mmax) {
				begin = end;
				maxValue = h[i];
				div++;
				if (maxValue + (end - begin) > mmax) {
					return false;
				}
			}
			i++;
		}
		return div <= k;
	};
	ll l = 0, r = 1e13;
	ll okay = 1e18;
	while (l <= r) {
		ll m = (l + r) / 2;
		if(check(m)) {
			r = m - 1;
			okay = m;
			continue;
		} else {
			l = m + 1;
		}
	}

	cout << okay << endl;

	return 0;
}
