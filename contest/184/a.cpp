#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;
using elem=array<int,4>;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector<elem> in(m);
	for (int i=0;i<m;i++){
		cin>>in[i][0]>>in[i][1]>>in[i][2]>>in[i][3];
		in[i][1]--,in[i][2]--;
	}
	vvii deltas(n);
	for (int i=0;i<m;i++){
		deltas[in[i][1]].emplace_back(in[i][0], -in[i][3]);
		deltas[in[i][2]].emplace_back(in[i][0], in[i][3]);
	}
	for(vii&t:deltas) sort(begin(t),end(t));
	int acc=0;
	for(int i=0;i<n;i++){
		vi pref(deltas[i].size() + 1);
		for (int j=0;j<deltas[i].size();j++)
			pref[j+1]=pref[j]+deltas[i][j].second;
		acc+=max(0ll, -*min_element(begin(pref), end(pref)));
	}

	cout<<acc<<endl;

	return 0;
}
