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
	int n,k;cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	vi gaps;
	for(int i=0;i+1<n;i++){
		gaps.push_back(a[i+1]-a[i]-1);
	}
	sort(rbegin(gaps),rend(gaps));
	
	int ans=a[n-1]-a[0]+1;
	for(int i=0;i<k-1;i++){
		ans-=gaps[i];
	}
	cout<<ans<<endl;
	return 0;
}
