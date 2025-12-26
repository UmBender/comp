#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();
	return 0;
}

struct BIT {
	i32 n;
	vector<i64> t;
	BIT(i32 _n) : n(_n + 1), t(_n + 1) {}

	void update(i32 pos, i64 value) {
		pos++;
		for (i32 i = pos; i < n; i += (-i & i)) {
			t[i] += value;
		}
	}

	void range_update(i32 l, i32 r, i64 val) {
		update(l, val);
		update(r + 1, -val);
	}

	i64 query(i32 pos) {
		i64 acc = 0;
		for (++pos; pos > 0; pos -= (-pos & pos)) {
			acc += t[pos];
		}
		return acc;
	}
};

struct Tree {
	vector<vector<i32>> adj;
	i32 n;
	vector<vector<i32>> childs;
	vector<i32> parents;
	vector<i32> height;
	vector<i32> in;
	vector<i32> out;
	vector<array<i32, 20>> bl;
	i32 root = 1;
	BIT bit;
	Tree(vector<vector<i32>> _adj)
		: adj(_adj), n(_adj.size()), childs(n), parents(n), height(n), in(n),
		out(n), bl(n), bit((n + 1) * 2) {
			i32 x = 1;
			function<void(i32, i32, i32)> dfs;
			dfs = [&](i32 actual, i32 last, i32 hh) {
				height[actual] = hh;
				parents[actual] = last;
				in[actual] = x;
				x++;
				for (i32 next : adj[actual]) {
					if (next == last) {
						continue;
					}
					childs[actual].push_back(next);
					dfs(next, actual, hh + 1);
				}
				out[actual] = x;
				x++;
			};
			dfs(1, 1, 0);

			for (i32 i = 1; i < n; i++) {
				bl[i][0] = parents[i];
			}
			for (i32 i = 1; i < 20; i++) {
				for (i32 j = 1; j < n; j++) {
					i32 temp = bl[j][i - 1];
					temp = bl[temp][i - 1];
					bl[j][i] = temp;
				}
			}
		}

	i32 succ(i32 node, i32 k) {
		for (i32 i = 0; i < 20; i++) {
			if ((k >> i) & 1) {
				node = bl[node][i];
			}
		}
		return node;
	}

	i32 lca(i32 r_first, i32 r_second) {
		if (height[r_first] > height[r_second]) {
			swap(r_first, r_second);
		}
		i32 first = r_first, second = r_second;
		second = succ(second, height[second] - height[first]);
		while (bl[first][0] != bl[second][0]) {
			bool finded = false;
			for (i32 i = 19; i > 1; i--) {
				if (bl[first][i] == bl[second][i] &&
						bl[first][i - 1] != bl[second][i - 1]) {
					first = bl[first][i - 1];
					second = bl[second][i - 1];
					finded = true;
					break;
				}
			}
			if (!finded) {
				first = bl[first][0];
				second = bl[second][0];
			}
		}
		if (first == second) {
			return first;
		}
		return bl[first][0];
	}
	void update(i32 a, i32 b) {
		i32 ancestor = lca(a, b);
		i32 begin = in[ancestor];
		bit.range_update(begin, in[a], 1);
		bit.range_update(begin + 1, in[b], 1);
	}
	vector<i32> get_result() {
		vector<i32> value(n - 1);
		for (i32 i = 1; i < n; i++) {
			i32 input = bit.query(in[i]);
			i32 output = bit.query(out[i]);
			value[i - 1] = input - output;
		}
		return value;
	}
};

void solution() {
	i32 n, m;
	cin >> n >> m;
	vector<vector<i32>> adj(n + 1);
	for (i32 i = 0; i < n - 1; i++) {
		i32 a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	Tree tree(adj);
	for (i32 mm{}; mm < m; mm++) {
		i32 a, b;
		cin >> a >> b;
		tree.update(a, b);
	}
	vector<i32> result = tree.get_result();
	for (i32 i = 1; i <= n; i++) {
		cout << result[i - 1] << " \n"[i == n];
	}
}
