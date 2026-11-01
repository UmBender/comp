#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    ll s = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s += x;
    }

    bool ans = (s%(__gcd(n-1,m)) == 0);
    if(ans) cout << "SIM" << endl;
    else cout << "NAO" << endl;
}
