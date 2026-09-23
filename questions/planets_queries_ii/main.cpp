#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"




int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vi adj(n + 1);
	for (int i = 1; i <= n; i++) cin >> adj[i];
	vi cntIn(n + 1), inCycle(n + 1), nodeTags(n + 1), reverseTags(n + 100), nodeCycle(n + 1), depth(n + 1);
	for (int i = 1; i <= n; i++) cntIn[adj[i]]++;

	vector<set<int>> cycles(n + 1);

	int tag = 1;
	queue<int> leafs;
	for (int i = 1; i <= n; i++) 
		if (cntIn[i] == 0)
			leafs.push(i);

	//cerr << "counted in edge" << endl;

	while (!leafs.empty()) {
		int actualNode = leafs.front();
		leafs.pop();
		nodeTags[actualNode] = tag++;
		cntIn[adj[actualNode]]--;
		if (cntIn[adj[actualNode]] == 0) {
			leafs.push(adj[actualNode]);
		}
	}

	//cerr << "taged leafs" << endl;

	for (int i = 1; i <= n; i++) {
		if (nodeTags[i] == 0) {
			int actualNode = i;
			while (nodeTags[actualNode] == 0) {
				cycles[i].insert(actualNode);
				nodeCycle[actualNode] = i;
				nodeTags[actualNode] = tag++;
				reverseTags[nodeTags[actualNode]] = actualNode;
				actualNode = adj[actualNode];
			}
		}
	}

	//cerr << "taged cycled" << endl;
	
	for (int i = 1; i <= n; i++) {
		if (nodeCycle[i] == 0) {
			stack<int> stackNodes;
			int actualNode = i;
			while (nodeCycle[actualNode] == 0) {
				stackNodes.push(actualNode);
				actualNode = adj[actualNode];
			}
			
			int findedCycle = nodeCycle[actualNode];
			int findedInCycle = !inCycle[actualNode] ? actualNode : inCycle[actualNode] ;
			int tempDepth = depth[actualNode] + 1;

			while (!stackNodes.empty()) {
				nodeCycle[stackNodes.top()] = findedCycle;
				inCycle[stackNodes.top()] =  findedInCycle;
				depth[stackNodes.top()] = tempDepth++; 
				stackNodes.pop();
			}
		}	
	}

	auto checkTags = [&]() {
		for (int i = 1; i <= n; i++) {
			cout << format("tag[{}]: {}, ", i, nodeTags[i]);
		}
		cout << endl;
	};

	auto checkInCycle = [&]() {
		for (int i = 1; i <= n; i++) {
			cout << format("inCycle[{}]: {}, ", i, inCycle[i]);
		}
		cout << endl;
	};

	auto checkNodeCycle = [&]() {
		for (int i = 1; i <= n; i++) {
			cout << format("nodeCycle[{}]: {}, ", i, nodeCycle[i]);
		}
		cout << endl;
	};

	auto checkDepth = [&]() {
		for (int i = 1; i <= n; i++) {
			cout << format("depth[{}]: {}, ", i, depth[i]);
		}
		cout << endl;
	};


	constexpr int log = 18;

	vvi bl(n + 1, vi(log));
	for (int i = 1; i <= n; i++) {
		bl[i][0] = adj[i];
	}

	for (int bit = 1; bit < log; bit++) {
		for (int i = 1; i <= n; i++) {
			bl[i][bit] = bl[bl[i][bit-1]][bit - 1];
		}
	}


		
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (a == b) { cout << 0 << endl; continue;}

		if (nodeCycle[a] != nodeCycle[b] 
				|| depth[a] < depth[b]) {
			cout << -1 << endl;
			continue;
		}
		if (inCycle[a] && inCycle[b]) {
			int dist = depth[a] - depth[b];
			int actual = a;
			for (int bit = 0; bit < log; bit++) {
				if ((dist >> bit) & 1ll) {
					actual = bl[actual][bit];
				}
			}
			if (actual != b) {
				cout << -1 << endl;
				continue;
			}
		}

		if (inCycle[a] && inCycle[b]) {
			cout << depth[a] - depth[b] << endl;
			continue;
		}

		int cost = depth[a];
		if (inCycle[a]) {
			a = inCycle[a];
		}
		if (nodeTags[a] <= nodeTags[b]) {
			cost += nodeTags[b] - nodeTags[a];
		} else {
			int size = cycles[nodeCycle[a]].size();
			cost += (size - nodeTags[a]) + nodeTags[b];
		}
		cout << cost << endl;
	}
}	
