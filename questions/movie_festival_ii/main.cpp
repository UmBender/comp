#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ab(n);
	for (auto &[a, b] : ab) { cin >> a >> b; }
	sort(ab.rbegin(), ab.rend());
	map<int, int> c;
	int ks = k;
	int counter = 0;
	for (auto [beginn, endd] : ab) {
		auto first = c.lower_bound(endd);
		if (first == c.end()) {
			if (ks) {
				c[beginn]++;
				ks--;
				counter++;
			}
		} else {
			c[first->first]--;
			c[beginn]++;
			if (c[first->first] == 0) { c.erase(first->first); }
			counter++;
		}
	}
	cout << counter << endl;
}
