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
	int a,b;
	cin >> a >> b;
	if ((a<0&& b<0)||(a>0&&b>0)) {
		cout<<"Yes"<<endl;
		return 0;
	}	
	cout<<"No"<<endl;
	return 0;
}
