#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int actual=0;
	int acc=0;
	for(int i=0;i<n;i++){
		acc+=actual;
		actual+=a[i];
	}
	cout<<acc<<endl;
	return 0;
}
