#include <bits/stdc++.h>
using namespace std;



int main() {
	int n, k;
	cin >> n >> k;
	int x[n];
	for (int i = 0; i < n; i++) cin >> x[i];
	map<int,int> acc;
	for (int i = 0; i < k; i++) {
		acc[x[i]]++;
	}
	cout << acc.size() << " ";
	for (int i = k; i < n; i++) {
		acc[x[i - k]]--;
		if (acc[x[i - k]] == 0) {
			acc.erase(x[i - k]);
		}
		acc[x[i]]++;
		cout << acc.size() << " ";
	}
	cout << endl;

	return 0;
}
