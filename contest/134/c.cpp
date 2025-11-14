#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) 
		solution();

	return 0;
}

void solution() {
    int n;
    cin >> n;
    int a[n];
    int actual = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        actual += a[i];
    }
    int pref[n + 1];
    pref[0] = 0;
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int mmax  = pref[n];
    int l[n+1];
    l[0] = INT64_MAX;
    for(int i = 1; i <= n; i++) {
        l[i] = i * i - i - pref[i - 1]; 
        l[i] = min(l[i], l[i-1]);
    }
    for(int i = 1; i <=n ;i++) {
        int sum = pref[n] - pref[i] +  i * i + i;
        sum -= l[i];
        mmax = max(sum, mmax);
    }
    cout << mmax << endl;


}
