#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	auto solution = [&](vi& a, int n) -> int {
		for (int i = 0; i < n; i++) a[i] = a[i] - i;
		sort(begin(a), end(a));
		a.erase(unique(begin(a), end(a)), end(a));
		reverse(begin(a), end(a));
		n = a.size();
		for (int i = 0; i < n; i++) a[i] = a[i] + i;
		int mmax = 0, actual = a[0], actualLen = 0;
		for (int i = 0; i < n; i++) {
			if (actual == a[i]) actualLen++;
			else {
				actual = a[i], actualLen = 1;
			}
			mmax = max(mmax, actualLen);
		}
		return mmax;
	};
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << solution(a, n) << endl;
	}
	return 0;
}	
