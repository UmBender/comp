#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int pref[300100][3];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	string s;cin>>s;
	for (int i=0;i<n;i++)for(int j=0;j<3;j++)
		pref[i+1][j]=pref[i][j]+(s[i]==('A'+j));

	int acc=0;
	auto check=[&](int l,int r)->bool{
		vi middle(3);
		for(int i=0;i<3;i++){
			middle[i]=pref[r+1][i]-pref[l][i];
		}
		for(int i=0;i<3;i++) if(!middle[i])return false;
		return true;
	};
	auto firstValid=[&](int pl,int pr)->int{
		int l=pl,r=pr,ans=-1;
		while(l<=r){
			int m=(l+r)/2;
			if(check(pl, m)){
				ans=m;
				r=m-1;
			}else l=m+1;
			}
		return ans;
	};
	auto lastValid=[&](int pl,int pr)->int{
		int l=pl,r=pr,ans=-1;
		while(l<=r){
			int m=(l+r)/2;
			if(check(m,pr)){
				ans=m;
				l=m+1;
			}else r=m-1;
		}
		return ans;
	};
	for(int i=0;i<n;i++){
		if(!check(0,i))continue;
		int p1=firstValid(i+1,n-1),p2=lastValid(i+1,n-1);
		if(p1==-1||p2==-1||p1>p2)continue;
		acc+=p2-p1;
	}
	cout<<acc<<endl;

	return 0;
}
