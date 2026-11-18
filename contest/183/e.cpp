#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int a[200100];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];

		int l=0,r=n-1;
		while(l<r&&a[l]==a[r])l++,r--;

		if(l>=r)cout<<"NO"<<endl;else{
			int x=1;
			while(x==a[l]||x==a[r])x++;
			cout<<"YES "<<x<<endl;
		}
	}
	return 0;
}



