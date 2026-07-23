#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
constexpr ll SIZE = 2e6 + 100;
ll mem[SIZE];

int inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

void setup() {
	mem[0] = 1;
	for (int i = 1; i < SIZE; i++) {
		mem[i] = i * mem[i - 1];
		mem[i] %= MOD;
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int n;
	cin >> n;
	if (n & 1) {
		cout << 0 << endl;
		return 0;
	}
	auto C = [&](int n, int k) -> int {
		ll top = mem[n];
		ll l1 = mem[k];
		ll l2 = mem[n - k];
		ll bottom = l1 * l2;
		bottom %= MOD;
		ll total = top * inv(bottom);
		total %= MOD;
		return total;
	};
	ll lin = inv(n / 2 + 1);

	ll total = lin * C(n, n / 2);
	total %= MOD;
	cout << total << endl;


	
}
