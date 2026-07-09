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
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n + 1), c(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}

	vector<priority_queue<int, vector<int>, greater<int>>> shops(m);
	while (q--) { 
		int p, d;
		cin >> p >> d;
		p--, d--;
		int prio = a[p];
		int cap = c[d];
		
		if (shops[d].size() < cap) {
			shops[d].push(prio);
		} else if (!shops[d].empty() && prio > shops[d].top()) {
			shops[d].pop();
			shops[d].push(prio);
		}
	}

	for (int i = 0; i < m; i++) {
		cout << shops[i].size() << " \n"[i == m - 1];
	}
    return 0;
}
