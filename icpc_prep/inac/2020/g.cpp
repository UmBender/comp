#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, p, q, s;
	cin >> n >> p >> q >> s;
	vector<ll> a(p), b(q);
	for (int i = 0; i < p; i++) cin >> a[i];
	for (int i = 0; i < q; i++) cin >> b[i];
	sort(begin(a), end(a));
	sort(begin(b), end(b));
	ll lo = -1, hi = 1e9 + 1;
	while (hi - lo > 1) {
		ll mid = lo + (hi - lo) / 2;
		multiset<ll, greater<ll>> st(begin(a), end(a));
		int cnt = 0;
		for (int i = q - 1; i >= 0; i--) {
			auto it = st.lower_bound(min(s - b[i], b[i] + mid));
			if (it == st.end()) {
				continue;
			}
			if (llabs(b[i] - *it) <= mid) {
				st.erase(it);
				cnt++;
			}
		}
		if (cnt >= n) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (hi > ll(1e9)) {
		cout << -1 << endl;
	} else {
		cout << hi << endl;
	}
}
