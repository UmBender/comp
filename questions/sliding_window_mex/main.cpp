#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	set<int> values;
	map<int, int> counter;
	for (int i = 0; i <= n; i++) {
		values.insert(i);
	}
	for (int i = 0; i < n; i++) {
		if(!values.count(x[i])) {
			values.insert(x[i]);
		}
	}

	for (int i = 0; i < k; i++) {
		if(counter[x[i]] == 0) { 
			values.erase(x[i]);
		}
		counter[x[i]]++;
	}
	cout << *values.begin() << " ";

	for (int i = k; i < n; i++) {
		counter[x[i - k]]--;
		if (counter[x[i - k]] == 0) {
			values.insert(x[i - k]);
		}
		if (counter[x[i]] == 0) {
			values.erase(x[i]);
		}
		counter[x[i]]++;
		cout << *values.begin() << " ";
	}
	cout << endl;

	return 0;
}
