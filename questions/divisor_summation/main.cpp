#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define int ll

constexpr int MAXX = 500100;

int spf[MAXX];
vector<int> primes;

void setup() {
	for (int i = 2; i < MAXX; i++) {
		if (!spf[i]) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j: primes) {
			if (i * j >= MAXX) break;
			spf[j * i] = j;
			if (spf[j] == i) break;
		}
	}
}


	

int32_t main() { 
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int n;
	cin >> n;
	auto fastExp = [](int base, int exp) -> int {
		if (base == 0) return 0;
		if (exp == 0) return 1;

		int acc = 1;
		while (exp) {
			if (exp & 1) {
				acc *= base;
			}
			base *= base;
			exp >>= 1;
		}
		return acc;
	};
	auto gs = [&](int a, int n) -> int {
		int first = fastExp(a, n + 1);
		int upper = first - 1;
		return upper / (a - 1);
	};
	auto calc = [&](int x) -> int {
		if (x == 0) return 0;
		if (x == 1) return 0;
		int acc = 1;
		int temp = x;
		while (temp > 1) {
			int div = spf[temp];
			int cnt = 0;
			while (temp % div == 0) {
				cnt++;
				temp /= div;
			}	
			acc *= gs(div, cnt);
		}	
		acc -= x;
		return acc;
	};

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cout << calc(x) << endl;
	}

	return 0;
}
