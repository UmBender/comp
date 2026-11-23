#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int b[200'100];
int dists[200'100],mmaxs[200'100], used[200'100], last[200'100];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m,s,t;
	cin>>n>>m>>s>>t;s--,t--;
	vvi adj(n);
	vvi radj(n);
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;a--,b--;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	mmaxs[s]=b[s];
	used[s]=1;
	for(int i=0;i<n;i++)dists[i]=1e9;
	for(int i=0;i<n;i++)last[i]=-1;
	dists[s]=0;
	using Node=array<int,2>;
	queue<Node> qq;
	qq.push({s,0});
	while (!qq.empty()){
		auto [node,dist]=qq.front();
		qq.pop();
		for(int next:adj[node]){
			if(dists[next]<dist+1)continue;
			if(mmaxs[next]<=mmaxs[node]+b[next]){
				last[next]=node;
				mmaxs[next]=mmaxs[node]+b[next];
				dists[next]=dist+1;
			}
			if(!used[next]) qq.push({next, dist+1});
			used[next]=1;
		}
	}
	if(dists[t]==1e9){
		cout<<-1<<endl;
		return 0;
	}
	cout<<dists[t]<<" "<<mmaxs[t]<<endl;
	vi path;
	int curr=t;
	while(curr!=-1){
		path.push_back(curr);
		curr=last[curr];
	}
	reverse(begin(path),end(path));
	for(int i=0;i<=dists[t];i++){
		cout<<path[i]+1<<" \n"[i==dists[t]];
	}
	return 0;
}
