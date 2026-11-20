#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int t[2600];

int comb(int n,int k){
	int up=1;
	int down=1;
	for (int i=k+1;i<=n;i++)up*=i;
	for (int i=1;i<=n-k;i++)down*=i;
	return up/down;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>t[i];
	vvii adj(2*n);
	for(int i=0;i<n-1;i++){
		int a,b,c;cin>>a>>b>>c;
		a--,b--;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	for(int i=0;i<n;i++){
		adj[i].emplace_back(n+i,t[i]);
	}
	vector<vector<map<int,int>>> possi(n);
	// actual, cost, last
	using Node=array<int,3>;
	int acc=0;
	for(int i=0;i<n;i++){
		if(adj[i].size()<4)continue;
		map<int,pii>temp;
		for(auto [child,baseCost]:adj[i]){
			if(child>=n)continue;
			queue<Node> qq;
			qq.push({child,baseCost,i});
			map<int,int> dists;
			while(!qq.empty()){
				// ja que nao gostam de actual
				Node curr=qq.front();
				qq.pop();
				if(curr[0]>=n){
					dists[curr[1]]++;
					continue;
				}
				for(auto [next,addCost]:adj[curr[0]]){
					if(next==curr[2])continue;
					qq.push({next,curr[1]+addCost,curr[0]});
				}
			}
			for(auto [dist,cnt]:dists){
				auto& [d1,d2]=temp[dist];
				acc+=d2*cnt;
				d2+=d1*cnt;
				d1+=cnt;
			}	
		}
	}

	cout<<acc<<endl;

	return 0;
}
