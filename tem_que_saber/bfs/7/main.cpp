#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int inf=1e9;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int h,w,p,k;cin>>h>>w>>p>>k;
	string grid[h];
	for(int i=0;i<h;i++)cin>>grid[i];
	pii start,target;
	string ks[k];
	for(int i=0;i<k;i++)cin>>ks[i];

	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if(grid[i][j]=='S')start={j,i};
		if(grid[i][j]=='T')target={j,i};
	}

	vector<vvi> dists(p,vvi(h,vi(w,inf)));

	using Node=array<int,4>;
	queue<Node> qq;
	qq.push({start.first,start.second,0,0});
	auto check=[&](int y, int x)->int{
		if(0>y||y>=h)return false;
		if(0>x||x>=w)return false;
		if(grid[y][x]=='#') return false;
		return true;
	};
	
	vii moves={{-1,0},{1,0},{0,-1},{0,1}};

	while(!qq.empty()){
		auto [x,y,iter,dist]=qq.front();
		qq.pop();
		for(auto [dy,dx]:moves){
			int ny=dy+y,nx=dx+x;
			if(!check(ny,nx))continue;
			if(grid[ny][nx]<'0'||grid[ny][nx]>'9'){
				if(dists[(iter+1)%p][ny][nx]>dist+1){
					dists[(iter+1)%p][ny][nx]=dist+1;
					qq.push({nx,ny,(iter+1)%p,dist+1});
				}
				continue;
			}
			int ch=grid[ny][nx]-'0';
			if(ks[ch][(iter+1)%p]=='1'&&dists[(iter+1)%p][ny][nx]>dist+1){
				dists[(iter+1)%p][ny][nx]=dist+1;
				qq.push({nx,ny,(iter+1)%p,dist+1});
			}
		}

		if(dist+1<dists[(iter+1)%p][y][x]){
			dists[(iter+1)%p][y][x]=dist+1;
			qq.push({x,y,(iter+1)%p,dist+1});
		}
	}

	int mmin=inf;
	for(int i=0;i<p;i++) mmin=min(mmin, dists[i][target.second][target.first]);

	if(mmin==inf){
		cout<<-1<<endl;
		return 0;
	}
	cout<<mmin<<endl;

	return 0;
}
