#include <bits/stdc++.h>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

const i64 MAX = 9e18;

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	i64 a[n + 1], b[n + 1];
	for(i32 i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(i32 i = 1; i <= n; i++) {
		cin >> b[i];
	}

	i64 actual = a[1];
	for(i32 i =2; i <= n; i++) {
		actual = gcd(actual, a[i]);
	}

	i64 acc_b = b[1];
	for(i32 i = 2; i <= n;i ++) {
		acc_b = gcd(acc_b, b[i]);
	}

	if(gcd(acc_b, actual) != 1) {
		cout << -1 << endl;
		return 0;
	}

	i64 temp = actual;
	vector<i64> p;
	for(i64 i = 2; i * i <= temp; i++) {
		if(temp % i == 0) {
			p.push_back(i);
			while(temp % i == 0) {
				temp /= i;
			}
		}
	}
	if(temp != 1) {
		p.push_back(temp);
	}

	i64 k = p.size();
	i64 limit = 1 << k;
	vector<i64> dp(limit, MAX);
	dp[0] = 0;
	for(i64 i = 1; i <= n; i++) {
		i64 mask = 0;
		for(i32 j = 0; j < k;j++){
			if(b[i] % p[j] !=0 ) {
				mask |= (1ll << j);
			}
		}
		if(mask ==0) {
			continue;
		}
		i64 cost = i * i + i;

		for(i64 j = limit - 1; j >= 0; j--)  {
			if(dp[j] == MAX) {
				continue;
			}
			i64 next = j | mask;
			if(dp[next] > dp[j] + cost) {
				dp[next] = dp[j] + cost;
			}
		}
	}

	if(dp[limit - 1] == MAX) {
		cout << -1 << endl;
	}else{
		cout << dp[limit-1] << endl;
	}
	
	return 0;
}
