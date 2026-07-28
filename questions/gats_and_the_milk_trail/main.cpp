#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	map<int,int> a;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			a.erase(i);
		}
	}	

	auto rem = [&](int l, int r, int x) -> int {
		auto it = a.lower_bound(l);
		int acc = 0;
		vector<int> removes;
		int last = -1;
		int deltaLast = -1;
		while (it != a.end() && it->first <= r && acc < x) {
			int tryRem = min(it->second, x - acc);
			acc += tryRem;
			if (it->second == tryRem) {
				removes.push_back(it->first);
			} else {
				last = it->first;
				deltaLast = tryRem;
			}
			it++;
		}
		for (int val: removes) {
			a.erase(val);
		}
		if (last != -1) {
			a[last] -= deltaLast;
		}
		return acc;
	};
	for (int qq = 0; qq < q; qq++) {
		char opt;
		cin >> opt;
		if (opt == 'D') {
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			int ans = rem(l, r, x);
			cout << ans << endl;
		} else {
			int i, x;
			cin >> i >> x;
			i--;
			a[i] += x;
		}
	}	

	return 0;
}
