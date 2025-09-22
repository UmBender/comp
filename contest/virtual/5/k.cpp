#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int left = max(a, c);
		int right = min(b, d);
		int intersection = max(0LL, right - left);
		cout << intersection << endl;
	}
	return 0;
}
