#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solution() {
	long long ih1, ih2, ib;
	double h1, h2, b;
	cin >> ih1 >> ih2 >> ib;
	h1 = (double)ih1;
	h2 = (double)ih2;
	b = (double)ib;

	double lh12 = log2((double)(h2 / h1));
	double lb = log2((double)((b - 1) / b));
	ll result = ceil(lh12 / lb);

	cout << result << '\n';
}

int32_t main() {
	long long n;
	cin >> n;
	while (n--) { solution(); }
	return 0;
}
