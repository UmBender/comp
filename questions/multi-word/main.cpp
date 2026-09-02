#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int p, q;
	cin >> p >> q;
	if (p == 0 || q == 0) {
		cout << "=" << endl;
		return 0;
	}

	int n, m;
	n = s.size(), m = t.size();
	int limit = n + m;
	for (int i = 0; i < limit; i++) {
		char ca = (i < n) ? s[i] : t[i - n];
		char cb = (i < m) ? t[i] : s[i - m];

		if (ca != cb) {
			cout << (ca < cb ? "<" : ">") << endl;
			return 0;
		}
	}
	cout << "=" << endl;
	return 0;
}
