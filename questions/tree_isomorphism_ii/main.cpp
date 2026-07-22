#include <bits/stdc++.h>
using namespace std;
using ll = long;

constexpr ll MOD = 1e9 + 9;
constexpr ll P = 676767677;
mt19937 rng(random_device{}());

void solution();

int main() {
		cin.tie(0)->sync_with_stdio(0);
		int t;
		cin >> t;
		while (t--) {
			solution();
		}
		return 0;
}

void solution() {
	int n;
	cin >> n;
	array<vector<vector<int>>, 2> adj;
	for (int i = 0; i < 2; i++) {
		adj[i] = vector<vector<int>>(n);
		for (int j = 0; j < n - 1; j++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[i][a].push_back(b);
			adj[i][b].push_back(a);
		}
	}
	array<vector<int>, 4> centers;
	vector<int> dists(n);
	vector<int> parent(n);

	function<void(int, int, int, int)> dfs1;
	dfs1 = [&](int actual, int last, int dist, int tree) {
		dists[actual] = dist;
		parent[actual] = last;
		for (int next: adj[tree][actual]) {
			if (next == last) continue;
			dfs1(next, actual, dist + 1, tree);
		}
	};
	function<vector<int>(int)> findCenters;
	findCenters = [&](int tree) -> vector<int> {
		fill(begin(dists), end(dists), 0);
		fill(begin(parent), end(parent), 0);
		dfs1(0, -1, 0, tree);
		int pos = max_element(begin(dists), end(dists)) - begin(dists);
		fill(begin(dists), end(dists), 0);
		fill(begin(parent), end(parent), 0);
		dfs1(pos, -1, 0, tree);
		pos = max_element(begin(dists), end(dists)) - begin(dists);
		vector<int> path;
		while (pos != -1) {
			path.push_back(pos);
			pos = parent[pos];
		}
		vector<int> p;
		p.push_back(path[path.size() / 2]);
		if (path.size() % 2) {
			return p;
		}
		p.push_back(path[path.size() / 2 -1]);
		return p;
	};
	centers[0] = findCenters(0);
	centers[1] = findCenters(1);
	vector<int> randoms(n + 1);
	for (int i = 0; i < n; i++) {
		randoms[i] = (abs<ll>(rng()) + 1) % MOD;
	}

	array<vector<ll>, 2> nodeHashes;
	for (int i = 0; i < 2; i++) {
		nodeHashes[i] = vector<ll>(n);
	}
	function<void(int, int, int)> dfs2;
	dfs2 = [&](int actual, int last, int tree) -> void {
		ll acc = 1;
		ll power = 1;
		vector<ll> childHashes;
		for (int next: adj[tree][actual]) {
			if (next == last) {
				continue;
			}
			dfs2(next, actual, tree);
			childHashes.push_back(nodeHashes[tree][next]);
		}
		ranges::sort(childHashes);
		for (int i = 0; i < childHashes.size(); i++) {
			ll temp = childHashes.at(i) * (i + 1);
			temp %= MOD;
			temp *= power;
			temp %= MOD;
			acc += temp;
			acc %= MOD;
			power *= P;
			power %= MOD;
		}
		nodeHashes[tree][actual] = acc;
	};
	for (int first: centers[0]) {
		dfs2(first, -1, 0);
		for (int second: centers[1]) {
			dfs2(second, -1, 1);
			ranges::sort(nodeHashes[0]);
			ranges::sort(nodeHashes[1]);
			/*
			for (int i = 0; i < n; i++) {
				cout << "first: " << nodeHashes[0][i] << " second: " << nodeHashes[1][i] << endl;
			}
			cout << "==============" << endl;
			*/
			if (nodeHashes[0] == nodeHashes[1]) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}
