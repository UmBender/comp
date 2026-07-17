#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef vector<int> vi;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

vi zFunc(string s) {
	int n = sz(s), l = 0, r = 0;
	vi z(n);
	if (!n) return z;
	rep(i, 1, n) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}
	z[0] = n;
	return z;
}

signed main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();

	if (m > n) {
		for (int i = n; i < m; i++) {
			if (t[i] != t[i % n]) {
				cout << 0 << endl;
				return 0;
			}
		}
		t = t.substr(0, n);
		m = n;
	}

	string ts = s;
	if (m > 1) {
		ts += s.substr(0, m - 1);
	}

	string concat = t + "#" + ts;
	vi z = zFunc(concat);
	int ans = 0;
	for (int i = m + 1; i < z.size(); i++) {
		if (z[i] == m) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
