#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,q;cin>>n>>q;
	vvi col(n);
	for(int i=0;i<n;i++)col[i].push_back(i+1);
	int w=n;
	auto opE=[&](int k){
		int nw=max(k,w-k);
		vvi nxt(nw);
		for (int i=k;i<w;i++)swap(nxt[i-k],col[i]);
		for (int i=0;i<k;i++) {
			int dest=k-1-i;
			for (auto it=col[i].rbegin();it!=col[i].rend();it++) 
				nxt[dest].push_back(*it);
		}
		swap(col,nxt);
		w=nw;
	};
	auto opD=[&](int k){
		int nw=max(k,w-k);
		vvi nxt(nw);
		int l=min(0,2*k-w);
		for(int i=0;i<k;i++)swap(nxt[i-l],col[i]);
		for(int i=k;i<w;i++){
			int dest=(2*k-1-i)-l;
			for (auto it = col[i].rbegin(); it != col[i].rend(); it++) {
				nxt[dest].push_back(*it);
			} 
		}
		swap(col,nxt);
		w=nw;
	};


	while(q--){
		char op;int k;
		cin>>op>>k;
		if(op=='E')opE(k);else opD(k);
	}
	cout<<w<<endl;
	for (int i=0;i<w;i++) {
		cout<<col[i].back()<<" \n"[i==w-1];
	}

	return 0;
}
