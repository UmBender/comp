#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vii=vector<pii>;
using vvii=vector<vii>;


string s[2010], u[2010];
int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vi used(n-1);
		for(int i=0;i<n;i++){cin>>s[i];}
		vvi adj(n-1);
		vi leafs,ans,cnt(n);
		for(int i=0;i<n-2;i++){
			if(s[i][i+2]=='0')cnt[i+1]++;
			else cnt[i]++;

			if(s[i][i+2]=='0')adj[i].push_back(i+1);
			else adj[i+1].push_back(i);
		}
		for(int i=0;i<n-1;i++) {
			if(!cnt[i])leafs.push_back(i);
		}
		while(!leafs.empty()){
			int actual=leafs.back();
			leafs.pop_back();
			ans.push_back(actual);
			for(int next:adj[actual]){
				cnt[next]--;
				if(!cnt[next])leafs.push_back(next);
			}
		}
		for(int i=0;i<n;i++){
			u[i]=string(n,'0');
			u[i][i]='1';
		}
		for(int i=0;i<n-1;i++){
			string temp=u[ans[i]];
			for(int j=0;j<n;j++)if(u[ans[i]+1][j]=='1')temp[j]='1';
			u[ans[i]]=temp;
			u[ans[i]+1]=temp;
		}
		bool okay=true;
		for(int i=0;i<n;i++)if(s[i]!=u[i]){
			cout<<"NO"<<endl;
			okay=false;
			break;
		}
		if(okay){
			cout<<"YES"<<endl;
			for(int i=0;i<n-1;i++)cout<<ans[i]+1<<" \n"[i==n-2];
		}
	}
	return 0;
}



