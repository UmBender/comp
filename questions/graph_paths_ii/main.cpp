#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
#define int ll
#define endl '\n'


constexpr int inf = 1e18 + 1000;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vvi adj(n, vi(n, inf));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a][b] = min(adj[a][b], c);
	}

	auto getIden = [&]() -> vvi {
		vvi ans(n, vi(n, inf));
		for (int i = 0; i < n; i++) ans[i][i] = 0;
		return ans;
	};

	auto mult = [&](vvi& first, vvi& second) -> vvi {
		vvi ans(n, vi(n, inf));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					i128 temp = i128(first[i][k]) + i128(second[k][j]);
					ans[i][j] = min<i128>(temp, ans[i][j]);
				}
			}
		}
		return ans;
	};

	auto fastExp = [&](vvi base, int exp) -> vvi {
		vvi ans = getIden();
		for (int i = 0; i < 32; i++) {
			if ((exp >> i) & 1) {
				ans = mult(ans, base);
			}
			base = mult(base, base);
		}
		return ans;
	};

	vvi ans = fastExp(adj, k);

	if (ans[0][n - 1] == inf) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans[0][n - 1] << endl;

	return 0;
}


