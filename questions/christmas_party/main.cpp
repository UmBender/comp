#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 100;
int fact[MAXN], invFact[MAXN];

inline int fastExp(int base, int exp) {
	if (base == 0) {
		return 0;
	}
	if (exp == 0) {
		return 1;
	}
	int acc = 1;
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


inline int getInv(int x) {
	return fastExp(x, MOD - 2);
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

inline int comb(int n, int k) {
	int up = fact[n];
	int low = (invFact[n - k] * invFact[k]) % MOD;
	return ((up * low) % MOD);
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int acc = 0;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		int sign = i % 2 == 0 ? 1 : -1;
		int reps = comb(n, i);
		int perms = fact[n - i];
		int temp = sign * ((reps * perms) % MOD);
		acc += temp;
		acc += MOD;
		acc %= MOD;
	}
	cout << acc << endl;

	return 0;
}
