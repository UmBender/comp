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

struct Edge {
	i32 next, link;
	char letter;
} adj[2100];

i32 mm = 1;
i32 head[2100];

struct Node {
	i32 a, b;
};

i32 main() {
	cin.tie(0)->sync_with_stdio(0);

	i32 n, m;
	cin >> n >> m;

	for (i32 i = 0; i < m; i++) {
		i32 a, b;
		char c;
		cin >> a >> b >> c;
		a--, b--;
		Edge edge_a = (Edge){
			.next = b,
			.link = head[a],
			.letter = c,
		};
		Edge edge_b = (Edge){
			.next = a,
			.link = head[b],
			.letter = c,
		};
		head[a] = mm;
		adj[mm++] = edge_a;
		head[b] = mm;
		adj[mm++] = edge_b;
	}

	vector<vector<i32>> dist(n, vector<i32>(n, INT32_MAX));
	dist[0][n - 1] = 0;
	dist[n - 1][0] = 0;
	i32 ans = INT32_MAX;
	queue<Node> q;
	q.emplace(0, n - 1);
	while (!q.empty()) {
		i32 a = q.front().a, b = q.front().b;
		q.pop();
		i32 a_actual = head[a];
		while (a_actual) {
			Edge a_edge = adj[a_actual];

			i32 b_actual = head[b];
			i32 size = dist[a][b];
			while (b_actual) {
				Edge b_edge = adj[b_actual];

				if (a_edge.letter != b_edge.letter) {
					b_actual = b_edge.link;
					continue;
				}
				if (dist[a_edge.next][b_edge.next] > size + 1) {
					dist[a_edge.next][b_edge.next] = size + 1;
					dist[b_edge.next][a_edge.next] = size + 1;
					q.emplace(a_edge.next, b_edge.next);
				}
				b_actual = b_edge.link;
			}

			a_actual = a_edge.link;
		}
	}

	for (i32 i = 0; i < n; i++) {
		if (dist[i][i] != INT32_MAX) {
			ans = min(ans, dist[i][i] * 2);
		}
		i32 actual = head[i];
		while (actual) {
			Edge e = adj[actual];
			if (dist[i][e.next] != INT32_MAX) {
				ans = min(ans, dist[i][e.next] * 2 + 1);
			}
			actual = e.link;
		}
	}
	if (ans == INT32_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;

	return 0;
}
