#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll s = max(0, a[i] - a[i-1]);
        ll c = min(a[i], a[i+1]);
        if(s > c){
            cout << -1 << endl;
            return 0;
        }
        ans += s;
    }

    cout << ans << endl;
}
