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
int MOD=998244353;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n,g;cin>>n>>g;
		for(int i=0;i<n;i++)cin>>a[i];
		int cnt=2;
		for(int i=0;i<n-2;i++)if(a[i+2]-a[i]<g)cnt=0;
		for(int i=0;i<n-1;i++)if(a[i+1]-a[i]>=g){
			cnt*=2;
			cnt%=MOD;
		}
		cout<<cnt<<endl;
	}
	return 0;
}



