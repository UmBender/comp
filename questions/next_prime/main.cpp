#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using i128 = __int128;
#define int ll
#define endl "\n"


bool checkPrime(ll p, ll a) {
	ll k = p - 1, d = 1;
	while (~k & 1) k >>= 1;
	for (ll e = k; e; e >>= 1) {
		if (e & 1) d = i128(d) * a % p;
		a = i128(a) * a % p;
	}
	if (d == 1 || d == p - 1) return true;
	while ((k <<= 1) < p - 1) {
		d = i128(d) * d % p;
		if (d == p - 1) return true;
	}
	return false;
}

bool isPrime(ll p) {
	if (p == 1) return false;
	for (int i: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (p == i) return true;
		if (!checkPrime(p, i)) return false;
	}
	return true;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		n++;
		while (!isPrime(n)) n++;
		cout << n << endl;
	}

	return 0;
}
