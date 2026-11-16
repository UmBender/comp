#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int acc = 1;
	int rest = c;
	for (int i = 0; i < n; i++) {
		if (a[i] > rest) {
			acc += 1;
			rest = c;
		}
		rest -= a[i];
	}
	cout << acc << endl;

    return 0;
}
