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
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	int m1, m2;
	cin >> m1;
	vector<vector<int>> g1(n+1);
	vector<vector<int>> g2(n+1);
	set<pair<int,int>> edge;
	vector<bool> good(n+1);
	for(int i = 0; i < m1; i++) {
		int a,b;
		cin >> a >> b;
		g1[a].push_back(b);
		g1[b].push_back(a);
		edge.insert({a,b});
		edge.insert({b,a});
	}
	cin >> m2;
	for(int i = 0; i < m2; i++) {
		int a,b;
		cin >> a >> b;
		g2[a].push_back(b);
		g2[b].push_back(a);
		if(edge.count({a,b})) {
			good[a] = true;
		}
		if(edge.count({b,a})) {
				good[b] = true;
		}
	}
	vector<vector<int>> d(n+1, vector<int>(n+1, MAX_INT));
	d[s1][s2] = 0;
	set<pair<int,pair<int,int>>> st;
	st.insert({0, {s1, s2}});
	while(!st.empty()) {
		auto [v,u] = st.begin()->second;
		st.erase(st.begin());
		for(auto to1: g1[v]) {
			for(auto to2: g2[u]) {
				int w = abs(to1 - to2);
				if(d[to1][to2] > d[v][u] + w) {
					st.erase({d[to1][to2], {to1, to2}});
					d[to1][to2]= d[v][u] + w;
					st.insert({d[to1][to2], {to1, to2}});
				}
			}
		}
	}
	int ans = MAX_INT;
	for(int i = 1; i<=n;i++) {
		if(good[i]) {
			ans = min(ans, d[i][i]);
		}
	}
	if(ans == MAX_INT) {
		ans = -1;
	}
	cout << ans << endl;
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
