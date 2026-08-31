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

#define int ll
constexpr int MOD = 1e9 + 7;
constexpr int MAX_V = 1e6 + 100;


vector<int> sieve(MAX_V);


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& vi: v) cin >> vi;
	sort(begin(v), end(v));
	int q;
	cin >> q;
	vector<int> x(q);
	for (int &xi: x) cin >> xi;
	vector<int> cntr(MAX_V);
	for (int i = 0; i < n; i++) {
		cntr[v[i]]++;
	}
	vector<int> mult(MAX_V);
	for (int i = 1; i < MAX_V; i++) {
		for (int j = i; j < MAX_V; j += i) {
			mult[i] += cntr[j];
		}
	}

	vector<int> spf(MAX_V);
	iota(begin(spf), end(spf), 0);

	for (int i = 2; i * i < MAX_V; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAX_V; j += i) {
				if (spf[j] == j) spf[j] = i;
			}
		}

	}

	auto fastExp = [](int base, int pot) -> int {
		int acc = 1;
		while (pot) {
			if (pot & 1) {
				acc *= base;
				acc %= MOD;
			}
			base = base * base;
			base %= MOD;
			pot /= 2;
		}
		return acc;
	};
	
	for (int qq: x) {
		vector<int> facts;
		int temp = qq;
		while (temp > 1) {
			int p = spf[temp];
			facts.push_back(p);
			while (temp % p == 0) {
				temp /= p;
			}
		}
		
		int bad = 0;
		int k = sz(facts);
		for (int mask = 1; mask < (1ll << k); mask++) {
			int prod = 1;
			int bits = 0;
			for (int i = 0; i < k; i++) {
				if ((mask >> i) & 1) {
					prod *= facts[i];
					bits++;
				}
			}
			if (bits & 1) {
				bad += mult[prod];
			} else {
				bad -= mult[prod];
			}
		}
		int good = n - bad;
		cout << fastExp(2, good) << endl;
	}

}
