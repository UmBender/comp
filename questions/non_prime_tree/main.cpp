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
int actual_even = 0;
int actual_odd = 0;



void dfs(vector<vector<int>> &adj, vector<int> &heights, int actual_node, int old_node, int height) {
	if(height & 1) {
		heights[actual_node] = actual_even;
		actual_even += 2;
	}else{
		heights[actual_node] = actual_odd;
		actual_odd-=2;
	}
	for(auto i: adj[actual_node]) {
		if(i != old_node){
			dfs(adj, heights,i, actual_node, height+1);
		}
	}
	if(abs(heights[actual_node] - heights[old_node]) == 2) {
		heights[actual_node] = heights[old_node] - 1;
	}
}



void solution() {
	int n;
	cin >> n;
	vector<vector<int>>adj(n+1);
	vector<int> key(n+1);
	vector<int> heights(n+1);
	actual_even = 2;
	actual_odd = 2* n;

	for(int i = 0; i < n-1; i++) {
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	dfs(adj, heights, 1, 1, 0);

	for(int i = 1; i <=n;i++) {
		cout << heights[i] << " \n"[i==n];
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
