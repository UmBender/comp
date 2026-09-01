#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int LOSING = 2;
constexpr int WINNING = 1;
constexpr int UNDEFINED = 0; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> dp(k + 1);
	dp[0] = WINNING;

	for (int i = 0; i <= k; i ++) {
		int tempState = LOSING;
		for (int j = 0; j < n; j++) {
			int actual = i;
			if (actual < a[j]) {
				break;
			}
			if (dp[actual - a[j]] == LOSING) { 
				tempState = WINNING;
			}
		}	

		dp[i] = tempState;
	}
	cout << (dp[k] == WINNING ? "First" : "Second") << endl;
	return 0;
}
