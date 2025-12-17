#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();
void setIO(string name = "") {
	if(!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("mootube");
	solution();
	return 0;
}



void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<map<i32,i64>> adj(n + 1);
	for(i32 nn = 0; nn < n - 1; nn++)  {
		i32 p, q;
		cin >> p >> q;
		i64 r;
		cin >> r;
		adj[p][q] = r;
		adj[q][p] = r;
	}
	auto query = [&](i64 k, i32 v) -> i32 {
		i32 counter = 0;
		queue<pair<i32,i32>> nodes;
		nodes.push({v, v});
		while(nodes.size()) {
			auto [actual, last] = nodes.front();
			nodes.pop();
			for(auto [next, value]: adj[actual]) {
				if(next == last) {
					continue;
				}
				if(value < k) {
					continue;
				}
				counter++;
				nodes.push({(i32)next, (i32)actual});
			}
		}
		return counter;
	};
	for(i32 qq = 0; qq < q; qq ++) {
		i64 kk, vv;
		cin >> kk >> vv;
		cout << query(kk, vv) << "\n";
	}
}
