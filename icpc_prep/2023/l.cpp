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
	string s;
	cin >> s;
	int k;
	int n = sz(s);
	cin >> k;


	vector<vector<char>> words(k);
	for (int i = 0; i < n; i++) {
		words[i % k].push_back(s[i]);
	}
	for (int i = 0; i < k; i++) {
		sort(begin(words[i]), end(words[i]));
	}
	string ans;
	for (int i = 0; i < n; i++) {
		ans += words[i % k][i / k];
	}
	cout << ans << endl;

	return 0;
}

