#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vii=vector<pii>;
using vvii=vector<vii>;

int p[200100],r[200100];
template<class S, S(*op)(S,S),S(*e)()>
struct Segtree{
	vector<S>t;
	int n;
	Segtree(int N):t(2*N,e()),n(N){}
	void set(int i,S value){
		t[i+=n]=value;
		for(i>>=1;i;i>>=1)t[i]=op(t[i<<1],t[i<<1|1]);
	}
	S query(int l,int r){
		S al=e(),ar=e();
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)al=op(al,t[l++]);
			if(r&1)ar=op(t[--r],ar);
		}
		return op(al,ar);
	}
};

struct Type{
	int mmin,acc;
};
Type top(Type a,Type b) {
	return Type{min(a.mmin, a.acc+b.mmin), a.acc+b.acc};
}
Type te(){
	return Type{int(1e15), 0};
}

using Seg=Segtree<Type,top,te>;
Seg st(800400);


int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>p[i]>>r[i];
	for(int i=0;i<2*n;i++){
		st.set(2*i,Type{-p[i%n],-p[i%n]});
		st.set(2*i+1,Type{r[i%n],r[i%n]});
	}
	int mmax=-1e15,acc=0;
	for(int i=0;i<n;i++){
		auto res=st.query(2*i,2*n+2*i);
		if(res.mmin==mmax)acc+=1;
		else if(res.mmin>mmax)mmax=res.mmin,acc=1;
	}
	cout<<-mmax<<" "<<acc<<endl;
	
	return 0;
}
