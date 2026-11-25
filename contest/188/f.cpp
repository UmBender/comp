#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

constexpr int mod = 998244353;
int a[200'100];
int dp[200'100];
int lc[200'100],rc[200'100];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			lc[i]=-1,rc[i]=-1;
		}
		for(int i=0;i<=n;i++)dp[i]=0;
		dp[n]=1;
		vi sp;
		for(int i=0;i<n;i++){
			int last=-1;
			while(!sp.empty()&&a[sp.back()]<a[i]){
				last=sp.back();
				sp.pop_back();
			}
			lc[i]=last;
			if(!sp.empty())rc[sp.back()]=i;
			sp.push_back(i);
		}
		using Node=array<int,3>;
		vector<Node> st;
		int cur=sp[0],cl=0,cr=n-1;
		while(cur!=-1||!st.empty()){
			while(cur!=-1){
				st.push_back({cur,cl,cr});
				cl=cur+1;
				cur=rc[cur];
			}
			auto[u,l,r]=st.back();
			st.pop_back();
			int lo=max(l,u+1-a[u]);
			int hi=min(u,r+1-a[u]);
			for(int j=lo;j<=hi;j++){
				dp[j]+=dp[j+a[u]];
				dp[j]%=mod;
			}
			cur=lc[u];
			cl=l;
			cr=u-1;
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}
