#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int counter = 0;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		int diff = 0;
		counter++;
		for (int j = 0; i - 1 - j >= 0 && i + j + 1 < n; j++) {
			if (s[i - 1 - j] != s[i + j + 1]) {
				diff++;
			}
			if (diff <= 1) {
				counter ++;
			} else {
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int diff = 0;
		for (int j = 0; j + 1 + i < n && i - j >= 0; j++) {
			if (s[i - j] != s[i + j + 1]) {
				diff++;
			}
			if (diff <= 1) {
				counter++;
			} else { 
				break;
			}
		}
	}
	cout << counter << endl;



	return 0;
}
