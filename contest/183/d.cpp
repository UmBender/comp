#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		int base=n+m-1;
		vii slow(k);
		for(auto &[a,b]:slow)cin>>a>>b;
		sort(begin(slow),end(slow));
		vi dp;
		for(auto [_,y]:slow){
			auto it=upper_bound(begin(dp),end(dp),y);
			if(it==end(dp))dp.push_back(y);else *it=y;
		}
		cout<<base+dp.size()<<endl;
	}
	return 0;
}



