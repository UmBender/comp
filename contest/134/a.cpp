#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) { solution(); }

	return 0;
}

void solution() {
	int n, a;
	cin >> n >> a;
	int v[n];
	for (int &i : v) { cin >> i; }

	int mmax = 0;
	int opt = a - 1;
	int counter{0};
	for (int i = 0; i < n; i++) {
		if (abs(opt - v[i]) < abs(a - v[i])) { counter++; }
	}
	mmax = counter;
	counter = 0;
	int temp = a + 1;
	for (int i = 0; i < n; i++) {
		if (abs(temp - v[i]) < abs(a - v[i])) { counter++; }
	}
	if (counter > mmax) { opt = temp; mmax = counter;}
	cout << opt << endl;
}
