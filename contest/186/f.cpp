#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int c[110],v[110];
int frees[10100], ans[10100];
int neg=-1e13;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>c[i]>>v[i];

	vvi byc(m+2);
	for(int i=0;i<n;i++){ byc[c[i]].push_back(v[i]); frees[c[i]]+=v[i]; }
	for(int j=1;j<=m;j++) frees[j]+=frees[j-1];

	vvi dp(n+1,vi(m+1,neg)), pm(n+1,vi(m+1,neg));
	dp[0][0]=0;
	auto rebuild=[&](){
		for(int i=0;i<=n;i++){
			int mmax=neg;
			for(int j=0;j<=m;j++){
				mmax=max(mmax,dp[i][j]);
				pm[i][j]=mmax;
			}
		}
	};
	rebuild();

	int r=m,cnt=0;
	ans[m]=frees[m];

	for(int j=m-1;j>=0;j--){
		if(!byc[j+1].empty()){
			int d=r-j;
			for(int i=1;i<=cnt;i++){
				int sh=i*d;
				for(int k=m;k>=0;k--)dp[i][k]=(k-sh>=0)?dp[i][k-sh]:neg;
			}
			r=j;
			for(int val:byc[j+1]){
				for(int i=cnt;i>=0;i--)for(int k=m-1;k>=0;k--)
					if(dp[i][k]!=neg) dp[i+1][k+1]=max(dp[i+1][k+1],dp[i][k]+val);
				cnt++;
			}
			rebuild();
		}
		int mmax=0;
		for(int i=0;i<=cnt;i++){
			int pos=m-i*(r-j);
			if(pos<0) break;
			mmax=max(mmax,pm[i][pos]);
		}
		ans[j]=frees[j]+mmax;
	}
	for(int i=0;i<=m;i++)cout<<ans[i]<<endl;

	return 0;
}
