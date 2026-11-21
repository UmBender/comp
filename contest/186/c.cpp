#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int c[300100],l[300100],r[300100];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>c[i];
	map<int,int>last;
	set<pii>pos;
	for(int i=0;i<n;i++){
		if(last.count(c[i]))pos.erase({-last[c[i]],c[i]});
		auto it=pos.lower_bound({-i, c[i]});
		if(it!=end(pos)){
			l[i]=i+it->first;
		}else l[i]=1e9;
		pos.insert({-i, c[i]});
		last[c[i]]=i;
	}
	last.clear();
	pos.clear();
	for(int i=n-1;i>=0;i--){
		if(last.count(c[i]))pos.erase({last[c[i]],c[i]});
		auto it=pos.lower_bound({i, c[i]});
		if(it!=end(pos)){
			r[i]=it->first-i;
		}else r[i]=1e9;
		pos.insert({i, c[i]});
		last[c[i]]=i;
	}
	for(int i=0;i<n;i++)cout<<min(l[i],r[i])<<" \n"[i==n-1];

	return 0;
}
