#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;


int a[110];
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		int cst=0;
		for(int i=0;i<n;i++)cst+=a[i];
		int mmax=0;
		for(int i=0;i<n-1;i++){
			int rem=(a[i]+a[i+1])/2;
			mmax=max(mmax,cst-rem);
		}
		cout<<mmax<<endl;
	}
	return 0;
}



