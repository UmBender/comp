#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
#define int ll
#define fi first
#define se second

constexpr int MAXN = 1e7 + 100;

pii pre[MAXN];
pii nil = make_pair(-1, -1);

vi join(pii f, pii s) {
	return {f.fi, f.se, s.fi, s.se};
}
void setup() {
	for (int i = 0; i < MAXN; i++) {
		pre[i] = nil;
	}

	for (int i = 0; i * i < MAXN; i ++) {
		pre[i * i] = {i, 0};
		for (int j = 0; j * j + i * i < MAXN && j <= i; j++) {
			pre[i * i + j * j] = {i, j};
		}
	}
}


vi calc(int n) {
	if (n == 0) return {};
	if (pre[n] != nil) return vector<ll>{pre[n].fi, pre[n].se};
	for (int i = 0; i < n; i++) {
		if (pre[i] == nil) continue;
		int rem = n - i;
		if (pre[rem] == nil) continue;
		return join(pre[rem], pre[i]);
	}
	return {};
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vi result = calc(n);
		while (result.size() < 4) result.push_back(0);
		for (int ri: result) {
			cout << ri << " ";
		}
		cout << endl;
	}

	return 0;
}
