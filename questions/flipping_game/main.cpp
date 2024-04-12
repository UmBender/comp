#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int a[110];
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, one = 0, sum = 0, ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		one += a[i];
	}

	ans = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			sum += 1;

		} else {
			sum -= 1;
		}
		ans = max(ans, sum);
		if (sum < 0)
			sum = 0;
	}
	if (one == n)
		cout << n - 1 << endl;
	else
		cout << one + ans << endl;

	return 0;
}
