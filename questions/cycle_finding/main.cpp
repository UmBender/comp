#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


struct Edge {
	ll a, b, m;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<ll> nodes(n, 1e15);
	vector<ll> parent(n);
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		ll a, b, m;
		cin >> a >> b >> m;
		a--, b--;
		edges.emplace_back(a, b, m);
	}
	for (int i = 0; i < n - 1; i++) {
		for(auto edge: edges) {
			if (nodes[edge.b] > nodes[edge.a] + edge.m) {
				nodes[edge.b] = nodes[edge.a] + edge.m;
				parent[edge.b] = edge.a;
			}
		}
	}

	vector<ll> path;
	set<ll> used;
	bool find = false;
	for (auto edge: edges) {
		if (nodes[edge.b] > nodes[edge.a] + edge.m) {
			find = true;
			path.push_back(edge.b);
			path.push_back(edge.a);
			used.insert(edge.b);
			used.insert(edge.a);
			break;
		}
	}

	if (!find) {
		cout << "NO" << endl;
		return 0;
	}

	bool loop = path[0] != path[1];
	while (loop) {
		if (used.count(parent[path.back()])) {
			loop = false;
		}
		used.insert(parent[path.back()]);
		path.push_back(parent[path.back()]);
	}
	reverse(path.begin(), path.end());
	while (path.back() != path.front()) {
		path.pop_back();
	}
	cout << "YES" << endl;
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] + 1 << " \n"[i == path.size() - 1];
	}
	

	

	return 0;
}	
