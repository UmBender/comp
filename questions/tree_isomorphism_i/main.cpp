#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

constexpr ll MOD = 1e9 + 9;
constexpr ll P = 676767677;
mt19937 rng(random_device{}());

void solution() {
	int n;
	cin >> n;
	array<vector<vector<int>>, 2> adj;
	array<vector<int>,2> nodeHashes;
	for (int i = 0; i < 2; i++) {
		adj[i] = vector<vector<int>>(n);
		nodeHashes[i] = vector<int>(n, 1);
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n - 1; j++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[i][a].push_back(b);
			adj[i][b].push_back(a);
		}
	}
	vector<ll> randoms(n + 1);
	for (int i = 0; i <= n; i++) {
		randoms[i] = rng() % MOD;
	}




	function<void(int, int, int)> dfs;
	dfs = [&](int actual, int parent, int tree) -> void {
		vector<ll> childHashes;
		for (int next: adj[tree][actual]) {
			if (next == parent) {
				continue;
			}
			dfs(next, actual, tree);
			childHashes.push_back(nodeHashes[tree][next]);
		}
		sort(begin(childHashes), end(childHashes));
		if(childHashes.size() == 0) {
			return;
		}
		ll acc = 1;
		ll power = P;
		for (int i = 0; i < childHashes.size(); i++) {
			ll temp = childHashes[i] * power;
			temp %= MOD;
			temp *= randoms[i];
			temp %= MOD;
			power *= P;
			acc += temp;
			acc %= MOD;
		}
		nodeHashes[tree][actual] = acc;
	};
	dfs(0, -1, 0);
	dfs(0, -1, 1);
	sort(begin(nodeHashes[0]), end(nodeHashes[0]));
	sort(begin(nodeHashes[1]), end(nodeHashes[1]));
	/*
	for (int i = 0; i < n; i++) {
		cout << format("first: {}, second: {}", nodeHashes[0][i], nodeHashes[1][i]) << endl;
	}
	*/
	cout << (nodeHashes[0] == nodeHashes[1] ? "YES" : "NO") << endl;
}

