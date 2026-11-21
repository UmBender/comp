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
	int n,m;cin>>n>>m;
	vector<string> g(n);
	for(auto&gi:g)cin>>gi;
	for(int i=0;i<n;i++){
		bool is=true;
		for(int j=0;j<m;j++)is&=g[i][j]=='x';
		if(is){
			cout<<"Faucet "<<i+1<<endl;
			return 0;
		}
	}
	for(int j=0;j<m;j++){
		bool is=true;
		for(int i=0;i<n;i++)is&=g[i][j]=='x';
		if(is){
			cout<<"Drain "<<j+1<<endl;
			return 0;
		}
	}
	return 0;
}
