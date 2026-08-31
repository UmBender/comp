#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

mt19937 rng(random_device{}());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string m, n;
	cin >> m >> n;

	vector<int> possiN;
	{
		function<void(int,int)> dfs;
		dfs = [&](int val, int pos) {
			if (pos == n.size()) {
				possiN.push_back(val);
				return;
			}
			int nVal = val * 2;
			if (n[pos] == '0' || n[pos] == '*') {
				dfs(nVal, pos + 1);
			}
			if (n[pos] == '1' || n[pos] == '*') {
				dfs(nVal + 1, pos + 1);
			}
		};
		dfs(0, 0);
	}

	function<bool(int)> dfs;
	string acc;

	dfs = [&](int pos) -> bool {
		if (pos == m.size()) {
			for (int modN: possiN) {
				int temp = 0;
				for (int i = 0; i < acc.size(); i++) {
					temp *= 2;
					temp += acc[i] - '0';
					temp %= modN;
				}
				if (temp == 0) {
					return true;
				}
			}
			return false;
		}

		if (m[pos] == '0' || m[pos] == '*') {
			acc += '0';

			if(dfs(pos + 1)) {
				return true;
			}
			acc.pop_back();
		}

		if (m[pos] == '1' || m[pos] == '*') {
			acc += '1';

			if(dfs(pos + 1)) {
				return true;
			}

			acc.pop_back();
		}
		return false;
	};
	dfs(0);
	cout << acc << endl;
}
