#include <bits/stdc++.h>
#include <cassert>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define sz(x) (int)((x).size()) 


vi kmp(string s) {
	int n = sz(s), len = 0;
	vi pre(n);
	rep (i,1,n) {
		while (len > 0 && s[i] != s[len]) len = pre[len - 1];
		if (s[i] == s[len]) len++;
		pre[i] = len;
	}
	return pre;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b, c;
	cin >> a >> b >> c;
	int n = ssize(a);
	b += b;
	int ans = 4 * n + 1;
	auto cons = [&](pair<int, int> rots) -> void {
		ans = min(ans, rots.first + rots.second);
		ans = min(ans, rots.first + n - rots.second);
		ans = min(ans, n - rots.first + rots.second);
		ans = min(ans, n - rots.first + n - rots.second);
	};
	auto consider = [&](pair<int, int> rots) -> void {
		for (int i = 0; i < 3; i++) {
			cons(rots);
			rots = pair(rots.second + n - rots.first, n - rots.first);
			if (rots.first >= n) rots.first -= n;
			if (rots.second >= n) rots.second -= n;
		}

	};
	for (int beg = 0; beg < n; beg++) {
		bool ok = 1;
		string t;
		const int x = int('A') + 'B' + 'C';
		for (int i = 0; i < n; i++) {
			if (a[i] == b[beg + i]) {
				ok = 0;
				break;
			}
			t += char(x - a[i] - b[beg + i]);
		}
		if (!ok) {
			continue;
		}
		string k = t + '$' + c + c;
		auto pre = kmp(k);
		for (int i = n + 1; i < ssize(k); i++) {
			if (pre[i] == n) {
				int off = i - 2 * n;
				consider(pair(beg, off));
			}
		}
	}
	if (ans > 4 * n) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}
