#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

constexpr int inf=1e9;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int h,w,k;cin>>h>>w>>k;

	vector<string>grid(h);
	for(int i=0;i<h;i++)cin>>grid[i];

	vector<vvi>dists(1<<k,vvi(h,vi(w,inf)));
	pii start,target;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if(grid[i][j]=='@')start={j,i};
		if(grid[i][j]=='$')target={j,i};
	}

	using Node=array<int,4>;
	queue<Node>qq;
	qq.push({start.first,start.second,0,0});
	dists[0][start.second][start.second]=0;

	auto check=[&](int x,int y,int keys)->bool{
		if(x<0||x>=w)return false;
		if(y<0||y>=h)return false;
		if(grid[y][x]=='#')return false;
		if(grid[y][x]=='.')return true;
		if(grid[y][x]=='$')return true;
		if(grid[y][x]=='@')return true;
		if(grid[y][x]>='a'&&grid[y][x]<='z')return true;
		int door=grid[y][x]-'A';
		return (keys>>door)&1;
	};

	vii moves={{-1,0},{1,0},{0,-1},{0,1}};
	while(!qq.empty()){
		auto [x,y,keys,cost]=qq.front();
		qq.pop();
		for(auto [dx,dy]:moves){
			int nx=dx+x,ny=dy+y;
			auto [tx,ty]=target;
			if(!check(nx,ny,keys))continue;

			int nkeys=keys;
			if(grid[ny][nx]>='a'&&grid[ny][nx]<='z')
				nkeys|=(1ll<<(grid[ny][nx]-'a'));

			if(tx==nx&&ny==ty){
				cout<<cost+1<<endl;
				return 0;
			}
			if(dists[nkeys][ny][nx]>cost+1){
				dists[nkeys][ny][nx]=cost+1;
				qq.push({nx,ny,nkeys,cost+1});
			}
		}
	}
	cout<<-1<<endl;
	
	return 0;
}
