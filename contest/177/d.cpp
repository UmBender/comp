#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	map<int, vector<int>> ver, hor;
	for (int i = 0; i < n; i++) {
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		ver[x].push_back(y);
		ver[x].push_back(r);
		ver[l].push_back(y);
		ver[l].push_back(r);
		hor[y].push_back(x);
		hor[y].push_back(l);
		hor[r].push_back(x);
		hor[r].push_back(l);
	}
	ll ans = 0;
	for (auto &[_, v]: ver) {
		sort(begin(v), end(v));
		assert(ssize(v) % 2 == 0);
		int n = ssize(v);
		for (int i = 1; i < n; i += 2) {
			ans += v[i] - v[i - 1];
		}
	}
	for (auto &[_, v]: hor) {
		sort(begin(v), end(v));
		assert(ssize(v) % 2 == 0);
		int n = ssize(v);
		for (int i = 1; i < n; i+= 2) {
			ans += v[i] - v[i - 1];
		}
	}
	cout << ans << endl;
}
