//#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)


#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;

vector<int> lps;
void build_lps(string& m) {
	int len = 0;
	lps = vector<int>(m.size());
	for(int i = 1; i < m.size(); i++) {
		lps[i] = lps[i-1];
		if(m[i] == m[len]) {
			len++;
			lps[i] = len;
		}	else {
			while(len > 0) {
				len = lps[len-1];
				if(m[i] == m[len]){
					break;
				}
			}
		}
		if(len == 0) {
			lps[i]=0;
			len = 0;
		} 
	}
}

void solution() {
	string n,m;
	cin >> n >> m;
	build_lps(m);
	vector<int> res;
	int i =0, j =0;
	while(i < n.size()) {
		if(n[i] == m[j]) {
			i++;
			j++;
			if(j == m.size()) {
				res.push_back(i - j);
				j = lps[j-1];
			}
		}else{
			if(j!=0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
	cout << res.size() << endl;
 
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
