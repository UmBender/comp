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
		int n,k;cin>>n>>k;
		if(n<k||n>k*2){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}
