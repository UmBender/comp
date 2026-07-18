#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int acc = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		if (s == "keep") {
			acc += b - a;
		}
	}
	cout << acc << endl;

	return 0;
}
