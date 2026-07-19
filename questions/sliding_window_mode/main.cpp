#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int n, k;
	cin >> n >> k;
	int x[n];
	for (int i = 0; i < n; i++) cin >> x[i];
	map<int,int> freq;
	set<pair<int,int>> vals;
	for (int i = 0; i < k; i++) {
		freq[x[i]]++;
	}
	for (auto &[k, v]: freq) {
		pair<int,int> actual = {v, -k};
		vals.insert(actual);
	}
	pair<int,int> res = *vals.rbegin();
	cout << -res.second << " ";
	for (int i = k; i < n; i++) {
		int oldVal = freq[x[i - k]]; 
		pair<int,int> rem = {oldVal, -x[i - k]};
		vals.erase(rem);
		freq[x[i - k]]--;
		oldVal = freq[x[i - k]];
		if (oldVal == 0) {
			freq.erase(x[i - k]);
		} else {
			rem = {oldVal, -x[i - k]};
			vals.insert(rem);
		}

		pair<int,int> newVal;
		if (freq[x[i]] != 0) {
			newVal = {freq[x[i]], -x[i]};
			vals.erase(newVal);
		}
		freq[x[i]]++;
		newVal = {freq[x[i]], -x[i]};
		vals.insert(newVal);
		
		pair<int,int> res = *vals.rbegin();
		cout << -res.second << " ";
	}
	cout << endl;
	return 0;
}
