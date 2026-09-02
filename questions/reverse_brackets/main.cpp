#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
constexpr int MOD = 998244353;
constexpr int MAXN = 5e3 + 100;
constexpr int RND = 676767677;
vector<int> fact(MAXN), invFact(MAXN);
vector<int> power(MAXN);

struct Hash {
	int hash;
	Hash(): hash(1) {}
	Hash(vector<Hash>& comp) {
		vector<int> nComp;
		for (int i = 0; i < comp.size(); i++) nComp.push_back(comp[i].hash);
		sort(begin(nComp), end(nComp));
		hash = nComp.size();
		for (int i = 0; i < nComp.size(); i++) {
			int temp = power[i + 1] * nComp[i];
			temp %= MOD;
			temp *= (i + 1);
			temp %= MOD;
			hash += temp;
			hash %= MOD;
		}
	}
};


struct Node {
	int begin, end, selfNum;
	Hash poly;
	vector<int> child;
};


int inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}



signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	s = "(" + s + ")";

	fact[0] = 1;
	invFact[0] = 1;
	power[0] = 1;

	for (int i = 1; i < MAXN; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		power[i] = (power[i - 1] * RND) % MOD;
	}

	invFact[MAXN - 1] = inv(fact.back());

	for (int i = MAXN - 2; i >= 0; i--) {
		invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
	
	vector<Node> nodes;
	nodes.emplace_back();
	{
		stack<int> sNodes;
		sNodes.push(0);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')') {
				Node& temp = nodes[sNodes.top()];
				temp.end = i;
				sNodes.pop();
				nodes[sNodes.top()].child.push_back(temp.selfNum);
			} else {
				Node nd;
				nd.begin = i;
				nd.selfNum = nodes.size();
				nodes.push_back(nd);
				sNodes.push(nd.selfNum);
			}
		}
	}

	map<int, int> cnt;
	{
		function<void(int)> dfs;
		dfs = [&](int node) {
			Node& actual = nodes[node];
			if (!actual.child.size()) {
				cnt[actual.poly.hash] = 1;
				return;
			}
			vector<Hash> hashes;
			map<int, int> count;
			int acc = 1;
			for (int next: actual.child) {
				dfs(next);
				hashes.push_back(nodes[next].poly);
				count[nodes[next].poly.hash]++;
				acc *= cnt[nodes[next].poly.hash];
				acc %= MOD;
			}

			for (auto [k, v]: count) {
				acc *= invFact[v];
				acc %= MOD;
			}

			acc *= fact[actual.child.size()];
			acc %= MOD;
			Hash actualHash(hashes);

			cnt[actualHash.hash] = acc;
			actual.poly  = actualHash;
		};
		dfs(1);
	}

	cout << cnt[nodes[1].poly.hash] << endl;
	return 0;
}
