#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	string acc;
	int n = s.size();
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			acc += s[i];
		} else {
			acc += s[i + 1];
			acc += s[i];
		}
	}
	cout << acc << endl;
	return 0;
}
