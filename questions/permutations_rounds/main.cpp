#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,a,b) for (int i = (a); i < (b); i++)

constexpr int MOD = 1e9 + 7;
using vi = vector<int>;

struct DSU {
	int n;
	vector<int> sizes, parents;
	DSU (int _n): n(_n), sizes(n, 1), parents(n) {
		iota(begin(parents), end(parents), 0ll);
	}

	int getParent(int node) {
		if (parents[node] == node) {
			return node;
		}
		parents[node] = getParent(parents[node]);
		return parents[node];
	}

	bool join(int first, int second) {
		first = getParent(first);
		second = getParent(second);
		if (first == second) return false;
		if (sizes[first] < sizes[second]) swap(first, second);
		sizes[first] += sizes[second];
		parents[second] = first;
		return true;
	}
};


struct Sieve {
	vi primes, spf;
	Sieve(int n): spf(n) {
		rep(i,2,n) {
			if (!spf[i]) {
				spf[i] = i;
				primes.push_back(i);
			}
			for (int j: primes) {
				if (j * i >= n) break;
				spf[i * j] = j;
				if (j == spf[i]) break;
			}
		}
	}
	map<int, int> getFactor(int val) {
		map<int, int> facts;
		while (val > 1) {
			int actual = spf[val];
			int counter = 0;
			while (val % actual == 0) {
				counter++;
				val /= actual;
			}
			facts[actual] = counter;
		}
		return facts;
	}
};

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	DSU dsu(n + 1);
	for (int i = 0; i < n; i++) {
		dsu.join(i + 1, p[i]);
	}
	vector<int> vals(n);
	for (int i = 0; i < n; i++) {
		vals[i] = dsu.sizes[dsu.getParent(i + 1)];
	}
	sort(begin(vals), end(vals));
	vals.erase(unique(begin(vals), end(vals)), end(vals));
	map<int, int> factors;
	Sieve sieve(3e5);

	for (int i = 0; i < vals.size(); i++) {
		auto temp = sieve.getFactor(vals[i]);
		for (auto [k, v]: temp) {
			factors[k] = max(factors[k], v);
		}
	}

	int acc = 1;
	for (auto [k, v]: factors) {
		for (int j = 0; j < v; j++) {
			acc *= k;
			acc %= MOD;
		}
	}
	cout << acc << endl;
	return 0;
}
