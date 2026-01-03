#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	i32 q;
	cin >> q;
	array<vector<i32>, 256> pref;
	for (i32 i = 0; i < 256; i++) {
		pref[i] = vector<i32>(s.size() + 1);
	}

	for (i32 i = 0; i < s.size(); i++) {
		for (i32 j = 0; j < 256; j++) {
			pref[j][i + 1] = pref[j][i] + (s[i] == j);
		}
	}
	while (q--) {
		i32 a,b;
		cin >> a >> b;
		a--, b--;
		if (a == b) {
			cout << "Yes" << endl;
			continue;
		}
		if(s[a] != s[b]) {
			cout << "Yes" << endl;
			continue;
		}
		array<i32, 256> result;
		for (i32 i = 0; i < 256; i++) {
			result[i] = pref[i][b + 1] - pref[i][a];
		}
		i32 counter = 0;
		for (i32 i = 0; i < 256; i++) {
			if(result[i]) {
				counter++;
			}
		}
		//cout << "a,b: " << a + 1 << " " << b + 1 << endl;
		//cout << "couter: " << counter << endl;
		if (counter >= 3) { 
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
