#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		string s;cin>>s;
		int mmin=1;
		for(int i=1;i<n;i++) if(s[i]!=s[i-1]) mmin++;
		if(k>=mmin&&k<=n)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
	return 0;
}



