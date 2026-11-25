#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int sum=accumulate(a,a+n,0ll);
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++){
			int tempSum=sum+a[i];
			int rem=max(a[i]*2, a[n-1]);
			ans=max(ans,tempSum-rem);
		}
		cout<<ans<<endl;
	}
	return 0;
}
