#include <bits/stdc++.h>
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
	int n,m;cin>>n>>m;
	vi prev(m,0),cur(m,0),ans(n);
	for(int i=0;i<n;i++){
		int in=(i==0?0:prev[0]);
		for(int j=0;j<m;j++){
			int p;cin>>p;
			int out=in+p;
			cur[j]=(j+1<m?max(out,prev[j+1]):out);
			in=cur[j];
		}
		ans[i]=cur[m-1];
		swap(prev,cur);
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];

	return 0;
}
