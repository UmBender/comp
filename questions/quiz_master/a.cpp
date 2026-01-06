#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();
vector<vector<i32>> factors(1e5 + 10);

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	for (i32 i = 1; i < factors.size() ; i++) {
		for (i32 j = i; j < factors.size(); j+= i) {
			factors[j].push_back(i);
		}
	}
	i32 t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}

void solution() {
	i32 n, m;
	cin >> n >> m;
	vector<i32> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<i32> sieve(m + 1);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	n = a.size();
	



	i32 counter = 0;
	i32 left = 0;
	i32 mmin = INT32_MAX;

	for (i32 i = 0; i < n; i++) {
		for (i32 j: factors[a[i]]) {
			if (j > m) {
				break;
			}
			if (sieve[j] == 0) {
				counter++;
			}
			sieve[j]++;
		}
		bool can_remove = counter == m;
		while (can_remove) {
			for (auto j: factors[a[left]]) {
				if (j > m) {
					break;
				}
				if (sieve[j] <= 1) {
					can_remove = false;
					break;
				}
			}

			if (can_remove) {
				for (auto j: factors[a[left]]) {
					if (j > m) {
						break;
					}
					sieve[j]--;
				}
				left++;
			}
		}
		
		if (counter == m) {
			mmin = min(a[i] - a[left], mmin);
		}
	}
	if (mmin == INT32_MAX) {
		mmin = -1;
	}
	cout << mmin << endl;

}
