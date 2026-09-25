#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vvi adj(2 * m + 1), radj(2 * m + 1);

	auto conv = [&](char op, int top) -> int {
		if (op == '+') return top;
		return top + m;
	};
	auto invConv = [&](char op, int top) -> int {
		if (op == '+') return conv('-', top);
		return conv('+', top);
	};
	for (int i = 0; i < n; i++) {
		char op1, op2;
		int top1, top2;
		cin >> op1 >> top1 >> op2 >> top2;

		int in1 = invConv(op1, top1), out1 = conv(op2, top2);
		int in2 = invConv(op2, top2), out2 = conv(op1, top1);
		adj[in1].push_back(out1);
		adj[in2].push_back(out2);
		radj[out1].push_back(in1);
		radj[out2].push_back(in2);
	}

	vi acess(2 * m + 1), scc(2 * m + 1), order;

	for (int i = 1; i <= 2 * m; i++) {
		if (acess[i]) continue;
		stack<pair<int, int>> nodes;
		nodes.push({i, 0});
		while (!nodes.empty()) {
			auto& [actual, cnt] = nodes.top();
			acess[actual] = 1;
			if (cnt == adj[actual].size()) {
				order.push_back(actual);
				nodes.pop();
				continue;
			}
			int next = adj[actual][cnt++];
			if (acess[next]) continue;
			nodes.push({next, 0});
		}
	}

	reverse(begin(order), end(order));
	fill(begin(acess), end(acess), 0);

	int iter = 1;
	for (int i = 0; i < 2 * m; i++) {
		int actual = order[i];
		if (acess[actual]) continue;
		stack<pair<int, int>> nodes;
		nodes.push({actual, 0});
		scc[actual] = iter++;
		acess[actual] = 1;

		while (!nodes.empty()) {
			auto& [temp, cnt] = nodes.top();

			if (radj[temp].size() == cnt) {
				nodes.pop();
				continue;
			}

			int next = radj[temp][cnt++];
			if (acess[next]) continue;
			acess[next] = 1;
			scc[next] = scc[temp];
			nodes.push({next, 0});
		}
	}

	bool possible = true;

	for (int i = 1; i <= m; i++) {
		if (scc[i] == scc[i + m]) possible = false;
	}

	if (!possible) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vvi ansAdj(iter);
	for (int i = 1; i <= 2 * m; i++) {
		int actual = scc[i];
		for (int next: adj[i]) {
			ansAdj[actual].push_back(scc[next]);
		}
	}

	for (int i = 1; i < iter; i++) {
		auto &arr = ansAdj[i];
		sort(begin(arr), end(arr));
		arr.erase(unique(begin(arr), end(arr)), end(arr));
	}

	vvi sccNodes(iter);
	for (int i = 1; i <= 2 * m; i++) {
		sccNodes[scc[i]].push_back(i);
	}

	vi used(iter);
	order.clear();
	for (int i = 1; i < iter; i++) {
		if (used[i]) continue;
		stack<pair<int, int>> nodes;
		used[i] = 1;
		nodes.push({i, 0});
		while (!nodes.empty()) {
			auto& [actual, cnt] = nodes.top();
			if (cnt >= ansAdj[actual].size()) {
				used[actual] = 2;
				order.push_back(actual);
				nodes.pop();
				continue;
			}


			int next = ansAdj[actual][cnt++];
			if (used[next]) continue;
			used[next] = 1;

			nodes.push({next, 0});
		}
	}

	vi sccUsed(iter);
	reverse(begin(order), end(order));
	vi sccAns;
	for (int i = 1; i < iter; i++) {
		if (sccUsed[i]) continue;
		sccAns.push_back(i);
		sccUsed[i] = 1;
		for (int clause: sccNodes[i]) {
			int inv = clause <= m ? clause + m : clause - m;
			sccUsed[scc[inv]] = 1;
		}
	}

	vi ans(m + 1);
	for (int actScc: sccAns) {
		for (int clause: sccNodes[actScc]) {
			int pos = clause <= m ? clause : clause - m;
			int sign = clause <= m ? 0 : 1;
			ans[pos] = sign;
		}	
	}
	for (int i = 1; i <= m; i++) {
		cout << (ans[i] ? "+" : "-") << " \n"[i == m];
	}

	return 0;
}
