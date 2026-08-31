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
	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cij;
			cin >> cij;
			adj[i][j] = cij;
			dp[i][j] = cij;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min({dp[i][j], dp[i][k] + dp[k][j]}); 
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] < adj[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}


	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i == k) continue;
			for (int j = 0; j < n; j++) {
				if (j == k) continue;
				dp[i][j] = min({dp[i][j], adj[i][k] + adj[k][j]}); 
			}
		}
	}

	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == adj[i][j]) {
				counter++;
			}
		}
	}

	cout << counter / 2 << endl;




	return 0;
}

