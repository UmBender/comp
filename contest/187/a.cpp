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
	vi a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(begin(a),end(a));
	a.erase(unique(begin(a),end(a)),end(a));
	int actual=-1,len=0,mmax=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-actual==1){len++;actual=a[i];mmax=max(len,mmax);}else{
			actual=a[i];
			len=1;
			mmax=max(len,mmax);
		}
	}
	cout<<mmax<<endl;

	return 0;
}
