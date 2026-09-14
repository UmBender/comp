#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 100;
#define endl '\n'

int nums[MAXN], spf[MAXN];
vector<int> primes;

void sieve() {
	for (int i = 2; i < MAXN; i++) {
		if (!spf[i]) {
			spf[i] = i;
			primes.push_back(i);
		}
		for (int j: primes) {
			if (j * i >= MAXN) break;
			spf[i * j] = j;
			if (j == spf[i]) break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int acc = a[0];
	for (int i = 0; i < n; i++) acc = gcd(a[i], acc);
	if (acc != 1) {
		cout << "not coprime" << endl;
		return 0;
	}

	sieve();
	

	auto check = [&](int x) -> bool {
		int temp = x;
		while (temp > 1) {
			int div = spf[temp];
			if (nums[div]) { return true; }
			nums[div] = 1;
			while (temp % div == 0) {
				temp /= div;
			}
		}
		return false;
	};

	for (int i = 0; i < n; i++) {
		if (check(a[i])) {
			cout << "setwise coprime" << endl;
			return 0;
		}
	}

	cout << "pairwise coprime" << endl;
	return 0;
}




