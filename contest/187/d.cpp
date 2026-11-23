#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	pii lr[n];
	for(int i=0;i<n;i++)cin>>lr[i].first>>lr[i].second;
	sort(lr,lr+n);

	int ans=1;
	int curr=lr[0].second;
	for(int i=1;i<n;i++){
		if(lr[i].first>curr){
			ans++;
			curr=lr[i].second;
		}else curr=min(curr,lr[i].second);
	}
	cout<<ans<<endl;

	return 0;
}
