#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		if(i*2==n-i){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}



