#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define int ll
#define endl '\n'


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
	i128 acc = 0;
	for (int i = 1; i < (1ll << k); i++) {
		i128 comp = 1;
		bool bigger = false;
		int bits = 0;
		for (i128 j = 0; j < k; j++) {
			if ((i >> j) & 1) {
				bits++;
				comp *= a[j];
			}
			if (comp > n) {
				bigger = true;
				break;
			}
		}
		if (bigger) continue;
		i128 rest = n / comp;
		if (bits % 2 == 0) {
			rest *= -1;
		}
		acc += rest;
	}
	cout << int(acc) << endl;
	return 0;
}	
