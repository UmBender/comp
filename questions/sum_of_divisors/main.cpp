#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
constexpr int MOD = 1e9 + 7;

ll inv2 = (MOD / 2) + 1;

int32_t main() {
	int n;
	cin >> n;
	ll actual = 1;
	ll acc = 0;
	while (actual <= n) {
		ll numDiv = n / actual;
		ll next = n / numDiv;
		ll temp = (next + actual) % MOD;
		temp *= ((next - actual + 1) %MOD);
		temp %= MOD;
		temp *= inv2;
		temp %= MOD;
		temp *= numDiv;
		temp %= MOD;
		acc += temp;
		acc %= MOD;
		actual = next + 1;
	}
	cout << acc << endl;

}

