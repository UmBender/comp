#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

mt19937 rng(random_device{}());

constexpr int MAX_DP = 100 * 100 + 10;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 != 0) {
		cout << -1 << endl;
		return 0;
	}
	sort(begin(a), end(a));
	if (a.back() * 2 > sum) {
		cout << -1 << endl;
		return 0;
	}
	int target = sum / 2;
	vector<int> dp(MAX_DP, -1);
	dp[0] = -2;
	for (int i = 0; i < n; i ++) {
		for (int j = target; j >= 0; j--) {
			if (j - a[i] < 0) {
				break;
			}
			int before = j - a[i]; 

			if (dp[before] != -1 && dp[j] == -1) {
				dp[j] = before;
			}
		}
	}
	if (dp[target] == -1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> first, second;
	
	map<int,int> mp;
	int temp = target;
	while (temp) {
		first.push_back(temp - dp[temp]);
		mp[first.back()]++;
		temp = dp[temp];
	}

	for (int i = 0; i < n; i++) {
		if (!mp.count(a[i])) {
			second.push_back(a[i]);
		} else {
			mp[a[i]]--;
			if (mp[a[i]] == 0) {
				mp.erase(a[i]);
			}
		}
	}

	vector<int> ans;
	int f = 0, s = 0;
	int p1 = 0, p2 = 0;
	while (p1 < first.size() && p2 < second.size()) {
		if (f <= s) {
			ans.push_back(first[p1]);
			f += first[p1];
			p1++;
		} else {
			ans.push_back(second[p2]);
			s += second[p2];
			p2++;
		}
	}
	while (p1 < first.size()) {
		ans.push_back(first[p1]);
		f += first[p1];
		p1++;
	}
	while (p2 < second.size()) {
		ans.push_back(second[p2]);
		s += second[p2];
		p2++;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;


}
