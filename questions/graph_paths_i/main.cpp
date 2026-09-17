#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vvi = vector<vector<int>>;
#define endl '\n'
 
constexpr int MOD = 1e9 + 7;
 
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; 
	cin >> n >> m >> k;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a][b]++;
	}
 
	auto mult = [&](vvi& first, vvi& second) -> vvi { 
		vvi ans(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int acc = 0;
				for (int k = 0; k < n; k++) {
					int temp = first[i][k] * second[k][j];
					temp %= MOD;
					acc += temp;
					acc %= MOD;
				}
				ans[i][j] = acc;
			}
		}
		return ans;
	};
 
	auto getIden = [&]() -> vvi {
		vvi ans(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			ans[i][i] = 1;
		}
		return ans;
	};
 
	auto fastExp = [&](vvi base, int exp) -> vvi {
		vvi acc = getIden();
		for (int i = 0; i < 32; i++) {
			if ((exp >> i) & 1) {
				acc = mult(base, acc);
			}
			base = mult(base, base);
		}
		return acc;
	};
 
	vvi ans = fastExp(adj, k);
	cout << ans[0][n-1] << endl;
 
	return 0;
}
