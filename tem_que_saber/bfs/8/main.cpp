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

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int h,w,b;cin>>h>>w>>b;
	string grid[h];for(int i=0;i<h;i++)cin>>grid[i];
	vvi dists(h,vi(w,inf));
	pii start,target;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if(grid[i][j]=='S')start={j,i};
		if(grid[i][j]=='T')target={j,i};
	}

	using Node=array<int,4>;
	queue<Node> qq;
	qq.push({start.first,start.second,0,0});
	dists[start.second][start.first]=0;

	vii moves={{-1,0},{1,0},{0,-1},{0,1}};


	auto check = [&](int x, int y, int used)->bool{
		if(used>b)return false;
		if(x<0||x>=w)return false;
		if(y<0||y>=h)return false;
		if(grid[y][x]=='#') return false;
		return true;
	};

	while(!qq.empty()){
		auto[x,y,used,cost]=qq.front();
		qq.pop();
		for (auto [dx,dy]:moves){
			int nx=dx+x,ny=dy+y;
			if(!check(nx,ny,used))continue;
			int nused=used+(grid[ny][nx]=='=' ? 1:0);
			if(nused>b)continue;
			int ndist=cost+1;
			if(ndist<dists[ny][nx]){
				auto [tx,ty]=target;
				if(tx==nx&&ty==ny){
					cout<<ndist<<endl;
					return 0;
				}
				dists[ny][nx]=ndist;
				qq.push({nx,ny,nused,ndist});
			}
		}
	}

	cout<<-1<<endl;
	return 0;
}
