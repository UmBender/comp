#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'


constexpr int MAXX = 1e6 + 100;

struct Sieve {
	vector<int> spf;
	vector<int> primes;
	Sieve(): spf(MAXX){
		for (int i = 2; i < MAXX; i++) {
			if (!spf[i]) {
				spf[i] = i;
				primes.push_back(i);
			}
			for (int j: primes) {
				if (j * i >= MAXX) break;
				spf[i * j] = j;
				if (spf[j] == i) break;
			}
		}
	}
};

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	Sieve sv;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(begin(a), end(a));
	int total = n * (n - 1) / 2;
	vector<int> cnt(MAXX);
	vector<int> sieve(MAXX);
	vector<int> numFacts(MAXX);
	vector<int> cntMult(MAXX);
	for (int i = 0; i < n; i++) cnt[a[i]]++;
	for (int i = 2; i < MAXX; i++) {

		for (int j = i; j < MAXX; j += i) {
			cntMult[i] += cnt[j];
		}

		if (!sieve[i]) {
			numFacts[i] = 1;
			for (int j = i + i; j < MAXX; j += i) {
				sieve[j] = 1;
			}
		}
		for (int j = i + i; j < MAXX; j += i) {
			numFacts[j] ++;
		}

	}

	for (int i = 2; i <= a.back(); i++) {
		int calc = (cntMult[i] - 1) * cntMult[i] / 2;
		if (!sieve[i]) {
			total -= calc;
		} else {
			int temp = i;
			int count = 0;
			int totalCount = 0;
			while (temp > 1 && count < 2) {
				count = 0;
				int div = sv.spf[temp];
				while (temp % div == 0) {
					totalCount++;
					count++;
					temp /= div;
				}
			}
			if (count >= 2) {
				continue;
			}
			if (totalCount % 2) {
				total -= calc;
			} else {
				total += calc;
			}
		}
	}
	cout << total << endl;

	return 0;
}
