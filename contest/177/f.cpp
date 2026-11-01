#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;

#define int ll

const ll mod = 998244353;

ll inv(ll a) {
	return a <= 1 ? a : mod - (ll)(mod / a) * inv(mod % a) % mod;
}

ll brute(vector<int> a) {
	int n = ssize(a);
	auto score = [&]() -> ll {
		ll ans = 0;
		vector<int> seen(n);
		for (int i = 0; i < n; i++) {
			if (!seen[a[i]]) {
				seen[a[i]] = 1;
				ans += i + 1;
			}
		}
		return ans;
	};
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(a[i], a[j]);
			ans += score();
			ans %= mod;
			swap(a[i], a[j]);
		}
	}
	return ans;
}

ll solve(vector<int> a) {
	int n = ssize(a);
	vector<vector<ll>> pos(n);
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i + 1);
	}
	ll ans = 0;
	for (int j = 0; j < n; j++) {
		auto &v = pos[j];
		if (ssize(v) == 0) continue;
		ll k = ssize(v);
		ll a = k * (k - 1) / 2;
		a %= mod;
		a += (n - k) * (n - k - 1) / 2;
		a %= mod;
		ans += v[0] * a % mod;
		ans %= mod;
		if (k == 1) {
			ans += (n * (n + 1) / 2 - v[0]) % mod;
			ans %= mod;
			continue;
		}
		a = (v[1] * (v[1] - 1) / 2 - v[0]) % mod;
		a %= mod;
		a += v[1] * (n - v[1] - (k - 2)) % mod;
		a %= mod;
		ans += a;
		ans %= mod;
		ll d = n - v[0];
		ans += ((d - k + 1) * (k - 1) % mod) * v[0] % mod;
		ans %= mod;
		ans += ((v[0] * (v[0] - 1) / 2) % mod) * (k - 1) % mod;
		ans %= mod;
	}
	// assert(ans == brute(a));
	return ans * inv((n * (n - 1) / 2) % mod) % mod;
}

mt19937 rng(random_device{}());

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	cout << solve(a) << endl;
}
