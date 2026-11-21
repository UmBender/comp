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
	vector<map<int,set<int>>> adj(n);
	for (int i=0;i<m;i++){
		int u,v,c;cin>>u>>v>>c;
		u--,v--;
		adj[u][c].insert(v);
	}
	vector<int> visits(n,0), firstColor(n,-2);
	using Node=array<int,3>;
	queue<Node> q;
	q.push({0,0,-1});
	while(!q.empty()){
		auto [u,d,c]=q.front(); q.pop();

		if(visits[u]==0){
			visits[u]=1;firstColor[u]=c;
			if(u==n-1){ cout<<d<<endl; return 0; }
			for(auto& [nc,vs]:adj[u]){
				if(nc==c)continue;
				for(int v:vs) if(visits[v]<2) q.push({v,d+1,nc});
			}
		}
		else if(visits[u]==1 && c!=firstColor[u]){
			visits[u]=2;
			auto it=adj[u].find(firstColor[u]);
			if(it!=adj[u].end())
				for(int v:it->second) if(visits[v]<2) q.push({v,d+1,firstColor[u]});
		}
	}
	cout<<-1<<endl;
	return 0;
}
