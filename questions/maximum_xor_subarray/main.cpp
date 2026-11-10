#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int x[n], pref[n + 1];
	for (int i = 0; i < n; i++) cin >> x[i];
	pref[0] = 0;
	for (int i = 0; i < n; i++) pref[i + 1] = pref[i] ^ x[i];
	set<int> added;
	added.insert(pref[0]);
	ll mmax = 0;
	for (int i = 1; i <= n; i++) {
		ll acc = 0;
		ll mask = 0;
		for (int j = 62; j >= 0; j--) {
			mask |= 1ll << j;
			if (!(pref[i] & (1ll << j))) {
				ll temp = acc | (1ll << j);
				auto it = added.lower_bound(temp);
				if (it == added.end()) { 
					continue;
				}
				
				if ((*it & mask) == temp) {
					acc = temp;
					mmax = max(*it ^ pref[i], mmax);
				}
			} else {
				ll temp = acc; 
				auto it = added.lower_bound(temp);
				if ((*it & mask) == temp) {
					acc = temp;
					mmax = max(*it ^ pref[i], mmax);
				}
			}
		}
		added.insert(pref[i]);
	}
	cout << mmax<< endl;

	return 0;
}
