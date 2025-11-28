#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII= vector<VII>;


struct qe {
	i32 node;
	i32 last;
	i32 path;
};

void printqe(qe x) {
	cout << "node: " << x.node << "\n";
	cout << "last: " << x.last << "\n";
	cout << "path: " << x.path << "\n";

}

const i32 INVALID = 1e8;
i32 main() {
	cin.tie(0)->sync_with_stdio(0);

	i32 n, m;
	cin >> n >> m;
	VVI adj(n);

	for(i32 i = 0; i < m; i++) {
		i32 a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	auto calc_shortest_path = [&](i32 node) -> i32 {
		VI shortest(n, INVALID);
		queue<qe> q;
		i32 minimal = INVALID;
		for(auto next: adj[node]) {
			shortest[next] = 1;
			q.push(qe{
					.node = next,
					.last = node,
					.path = 1,
					});
			
		}
		while(!q.empty()) {
			qe actual = q.front();
			q.pop();
			for(i32 next: adj[actual.node]) {

				if(next == actual.last) {
					continue;
				}
				if(shortest[next] != INVALID) {
					minimal = min(actual.path + shortest[next] + 1, minimal);
					continue;
				}
				shortest[next] = actual.path + 1;
				qe x = qe {
						.node = next,
						.last = actual.node,
						.path = actual.path + 1,

						};
				q.push(x);

			}
		}
		return minimal;
	};

	i32 minimal = INVALID;
	for(i32 i = 0; i < n; i++) {
		minimal = min(minimal, calc_shortest_path(i));
	}
	if(minimal == INVALID) {
		minimal = -1;
	}	
	cout << minimal << '\n';


	return 0;
}
