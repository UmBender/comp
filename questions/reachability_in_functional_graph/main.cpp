#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<ll>;
#define int ll

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vi adj(n + 1), cnt(n + 1);
	for (int i = 1; i <= n; i++) cin >> adj[i];

	for (int i = 1; i <= n; i++) {

		if (cnt[i]) {
			continue;
		}

		int a = i;
		int b = i; 
		int op = 0;
		do {
			op++;
			a = adj[a];
			b = adj[adj[b]];
		} while (a != b && !cnt[a]);
		if (cnt[a]) {
			b = i;
			while (!cnt[b]) {
				cnt[b] = cnt[a] + op;
				op--;
				b = adj[b];
			}
			continue;
		}

		a = i;
		int mu = 0;
		while (a != b) {
			a = adj[a];
			b = adj[b];
			mu++;
		}

		int cycle = 1;
		b = adj[a];

		while (a != b) {
			b = adj[b];
			cycle++;
		}

		a = i;
		while (mu) {
			cnt[a] = mu + cycle;
			mu--;
			a = adj[a];
		}
		while (!cnt[a]) {
			cnt[a] = cycle;
			a = adj[a];
		}

	}

	int sum = accumulate(begin(cnt), end(cnt), 0ll);
	cout << sum << endl;
	return 0;
}

