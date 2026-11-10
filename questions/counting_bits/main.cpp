#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n = 1e7; 
	cin >> n;
	auto calc = [](int n) -> int {
		int acc{0};
		for (int i = 62; i >= 0; i--) {
			if (n & (1ll << i)) {
				acc += (1ll << (i - 1)) * (i);
				n -= (1ll << i);
				acc += (n + 1);
			}
		}
		return acc;
	};
	cout << calc(n) << endl;
		

	return 0;
}
