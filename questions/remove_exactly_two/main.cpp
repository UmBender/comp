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

void solution() {
	int n;
	cin >> n;
	vector<set<int>>adj(n+1);
	for(int i = 0; i < n -1; i++) {
		int a,b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int conc = 1;
	int max_adj = -1;
	set<int> possible_solution;
	for(int i = 1; i <= n; i ++) {
		if(((int)adj[i].size()) == max_adj) {
			possible_solution.insert(i);
		}
		if(((int)adj[i].size()) > max_adj) {
			possible_solution.clear();
			possible_solution.insert(i);
			max_adj = adj[i].size();
		}

	}
	int non_dec = -1;
	for(auto i: possible_solution) {
		for(auto j: possible_solution) {
			if(i == j) {
				continue;
			}
			if(!adj[i].count(j)) {
				non_dec = i;
				break;
			}
		}
		if(non_dec != -1) {
			break;
		}
	}
	int node_to_remove = non_dec;
	if(non_dec == -1) {
		node_to_remove = *possible_solution.begin();
	}
	conc += adj[node_to_remove].size() - 1;
	for(int i = 1; i <= n;i++) {
		if(i == node_to_remove) {
			continue;
		}
		if(adj[i].count(node_to_remove)) {
			adj[i].erase(node_to_remove);
		}
	}
	max_adj = -1;
	int max_node = -1;
	for(int i = 1; i <= n; i ++) {
		if(i == node_to_remove) {
			continue;
		}
		if(((int)adj[i].size()) > max_adj) {
			max_node = i;
			max_adj = adj[i].size();
		}
	}
	conc += max_adj - 1;
	cout << conc << endl;
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
