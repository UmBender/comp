#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
static constexpr ll MAX_N = 510;

ll dp[MAX_N][MAX_N];


int32_t main() {
	 cin.tie(0)->sync_with_stdio(0);
	 int n;
	 cin >> n;
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 dp[i][j] = 1e9;
		 }
	 }
	 int a[n];
	 for (int i = 0; i < n; i++) {
		 cin >> a[i];
	 }
	 for (int i = 0; i < n; i++) {
		 dp[i][i] = 1;
	 }
	 for (int i = 0; i < n - 1; i++) {
		 dp[i][i + 1] = a[i] == a[i + 1] ? 1 : 2;
	 }
	 for (int l = 3; l <= n; l++) {
		 for (int i = 0; i + l - 1 < n; i++)  {
			 if (a[i] == a[i + l - 1]) {
				dp[i][i + l - 1] = min(dp[i][i + l - 1],dp[i + 1][i + l - 2]);
			 }
			 for (int k = i; k < i + l - 1; k++) {
				 dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][k] + dp[k + 1][i + l - 1]);
			 } 

		 }
	 }
	 cout << dp[0][n - 1] << endl;


	
	 return 0;
}
