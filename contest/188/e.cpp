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
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a=0,b=0,c=0;
		if(m>=2*n) a=n;
		else if(n>=2*m) b=m;
		else {
			int rem=(n+m)%3;
			int rn=n,rm=m;
			if(rem==1){
				if(rn>=rm)rn--;
				else rm--;
			}else if (rem==2){
				c=1,rn--,rm--;
			}
			int q=(rn+rm)/3;
			a=rm-q;
			b=rn-q;
		}
		vector<string>grid(n,string(m,'.'));
		int r=0,col=0;
	
		for (int i=0;i<a;i++) {
			grid[r][col]='R';
			grid[r][col+1]='R';
			r+=1;
			col+=2;
		}
		for (int i=0;i<b;i++) {
			grid[r][col]='R';
			grid[r+1][col]='R';
			r+=2;
			col+=1;
		}
		for (int i=0;i<c;i++) {
			grid[r][col]='R';
			r+=1;
			col+=1;
		}
		cout<<2*a+2*b+c<<endl;
		for(int i=0;i<n;i++)cout<<grid[i]<<endl;
	}

	return 0;
}
