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
	int x, n;
	cin >> x >> n;
	vector<int> p(n);
	for(auto &i: p) {
		cin >> i;
	}
	priority_queue<tuple<int,int,int>> pq;
	set<int> nodes;
	pq.push({x, 0, x});
	for(int i = 0; i < n; i++) {
		bool correct = false;
		nodes.insert(p[i]);
		while(!correct) {
			auto [size, l,r] = pq.top();
			auto se = nodes.lower_bound(l);
			if(se == nodes.end()) {
				correct = true; continue;
			}
			if(*se > r) {
				correct = true;
				continue;
			}
			nodes.erase(*se);
			pq.pop();
			pq.push({ *se - l, l , *se});
			pq.push({r - *se, *se, r});
		}
		auto [neu,a,b] = pq.top();
		cout << neu  << " \n"[i ==n-1];
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
