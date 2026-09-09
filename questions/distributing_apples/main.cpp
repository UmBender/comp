#include <bits/stdc++.h>
#include <cassert>

using namespace std;
using ll = long long;

#define int ll

constexpr int MAXN = 2e6 + 100;
constexpr int MOD = 1e9 + 7;
int fact[MAXN], invFact[MAXN];

int fastExp(int base, int exp) {
	int acc = 1;
	if (acc == 0) {
		return 1;
	}
	while (exp) {
		if (exp & 1) {
			acc *= base;
			acc %= MOD;
		}
		base *= base;
		base %= MOD;
		exp >>= 1;
	}	
	return acc;
}

int getInv(int base) {
	return fastExp(base, MOD - 2);
}	

void setup() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	invFact[MAXN - 1] = getInv(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; i--) {
		invFact[i] = invFact[i + 1] * (i + 1);
		invFact[i] %= MOD;
	}
}

int getComb(int n, int k) {
	int up = fact[n];
	int base = invFact[n - k] * invFact[k];
	base %= MOD;
	return (base * up) % MOD;
}	


int32_t main() {
	setup();
	int n, m;
	cin >> n >> m;
	cout << getComb(n + m - 1, n - 1) << endl;

	return 0;
}
