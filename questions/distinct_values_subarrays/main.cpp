#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int x[200100];
signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	int counter = 0;
	set<int> pos;
	map<int, int> a;
	for (int i = 0; i < n; i++) {
		if (a.count(x[i])) {
			vector<int> pos_remove;
			auto iter = pos.begin();
			while (*iter != a[x[i]]) {
				pos_remove.push_back(*iter);
				iter++;
			}
			pos_remove.push_back(a[x[i]]);
			for (auto value : pos_remove) {
				a.erase(x[value]);
				pos.erase(value);
			}
		}
		a[x[i]] = i;
		pos.insert(i);
		counter += pos.size();
	}
	cout << counter << endl;
	return 0;
}
