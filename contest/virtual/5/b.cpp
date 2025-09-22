#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);

	for (auto &i : a) { cin >> i; }
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + a[i]; }
	int acc = 0;
	for (int i = n; i > 0; i--) { acc += pref[i] * i; }
	for (int i = 0; i < n; i++) { acc -= pref[i] * (n - i); }
	cout << acc << endl;

	return 0;
}
