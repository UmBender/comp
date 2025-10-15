#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }

void solution() {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; i++) { cin >> t[i]; }
	sort(t, t + n);
	if (n == 1) {
		cout << t[0] * 2 << endl;
		return;
	}

	int acc = 0;
	for (int i = 0; i < n - 1; i++) { acc += t[i]; }
	if (acc >= t[n - 1]) {
		cout << acc + t[n - 1] << endl;
	} else {
		cout << t[n - 1] * 2 << endl;
	}
}
