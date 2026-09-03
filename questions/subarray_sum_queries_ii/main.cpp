#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll


template<class S, S(*op)(S, S), S(*e)()>
struct Segtree {
	vector<S> t;
	int n;
	Segtree(int N): t(2 * N, e()), n(N) {}
	void set(int i, S value) {
		t[i += n] = value;
		for (i >>= 1; i; i >>= 1) t[i] = op(t[i << 1], t[i << 1 | 1]);
	}
	S query(int l, int r) {
		S al = e(), ar = e();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) al = op(al, t[l++]);
			if (r & 1) ar = op(t[--r], ar);
		}
		return op(al, ar);
	}
};

struct Node {
	int maxVal, lowest, maximum;
};

Node eNode() {
	return Node { 0, int(1e18), int(-1e18)};
}

Node opNode(Node a, Node b) {
	return Node {
		max({a.maxVal, b.maxVal, b.maximum - a.lowest}),
		min(a.lowest, b.lowest),
		max(a.maximum, b.maximum)
	};
}	

using Seg = Segtree<Node, opNode, eNode>;

int32_t main() {
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + x[i];
	}

	Seg seg(n);
	for (int i = 0; i < n; i++) {
		Node temp = { max(0ll, x[i]), pref[i], pref[i + 1]};
		seg.set(i, temp); 
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		Node result = seg.query(a, b + 1);
		cout << result.maxVal << endl;
	}

	return 0;
}
