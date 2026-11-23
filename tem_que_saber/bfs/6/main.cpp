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
	int h,w;cin>>h>>w;
	vector<string>grid(h);
	for(int i=0;i<h;i++)cin>>grid[i];
	int sx,sy,ex,ey;
	vii fires;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
			if(grid[i][j]=='S')sx=j,sy=i;
			if(grid[i][j]=='E')ex=j,ey=i;
			if(grid[i][j]=='F')fires.emplace_back(j,i);
	}
	vvi dists(h,vi(w,-1));
	queue<pii>ofires,nfires,opos,npos;
	auto isOkay = [&](int y,int x)->bool{
		if(y<0||y>=h)return false;
		if(x<0||x>=w)return false;
		if(grid[y][x]=='#'||grid[y][x]=='F')return false;
		return true;
	};
	dists[sy][sx]=0;
	opos.push({sx,sy});
	for(auto [fx,fy]:fires)ofires.push({fx,fy});


	vii moves={{-1,0},{1,0},{0,-1},{0,1}};
	while(!opos.empty()){
		while(!ofires.empty()){
			auto [fx,fy]=ofires.front();
			ofires.pop();
			for(auto [dx,dy]: moves){
				if(!isOkay(dy+fy,dx+fx))continue;
				nfires.push({dx+fx,dy+fy});
				grid[dy+fy][dx+fx]='F';
			}
		}
		swap(nfires,ofires);
		while(!opos.empty()){
			auto [ox,oy]=opos.front();
			opos.pop();
			for(auto [dx,dy]:moves){
				if(!isOkay(dy+oy,dx+ox)||dists[dy+oy][dx+ox]!=-1)continue;
				npos.push({dx+ox,dy+oy});
				dists[dy+oy][dx+ox]=dists[oy][ox]+1;
			}
		}
		swap(npos,opos);
	}

	if(dists[ey][ex]==0||dists[ey][ex]==-1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<dists[ey][ex]<<endl;
	return 0;
}
