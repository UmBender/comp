#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'

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

pair<int, int> ePair() {
	return {-1, 1e8};
}

pair<int, int> opPair(pair<int, int> first, pair<int, int> second) {
	return { max(first.first, second.first), min(first.second, second.second) };
}

using Seg = Segtree<pair<int, int>, opPair, ePair>;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	vector<int> comp;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		comp.push_back(x[i]);
	}

	vector<tuple<int, int, int>> queries(q);
	for (auto &[op, f, s]: queries) {
		cin >> op >> f >> s;
		if (op == 1) {
			comp.push_back(s);
		}
	}

	sort(begin(comp), end(comp));
	comp.erase(unique(begin(comp), end(comp)), end(comp));
	auto getComp = [&](int value) -> int {
		return lower_bound(begin(comp), end(comp), value) - begin(comp);
	};

	vector<set<int>> positions(comp.size());
	for (int i = 0; i < n; i++) {
		positions[getComp(x[i])].insert(i);
	}

	auto getPred = [&](int val, int pos) -> int {
		auto &ss = positions[getComp(val)];
		auto it = ss.find(pos);
		if (it != ss.begin()) {
			it--;
			return *it;
		}
		return -1;
	};

	auto getSucc = [&](int val, int pos) -> int {
		auto &ss = positions[getComp(val)];
		auto it = ss.find(pos);
		it++;
		if (it == ss.end()) {
			return 1e8;
		}
		return *it;
	};


	Seg seg(n);

	auto updateNeigh = [&](int val, int pos) {
		int before = getPred(val, pos);
		int next = getSucc(val, pos);
		seg.set(pos, {before, next});
	};


	auto update = [&](int val, int pos) {
		int last = x[pos];
		x[pos] = val;

		auto [oldBefore, oldNext] = seg.query(pos, pos + 1);

		positions[getComp(last)].erase(pos);
		positions[getComp(val)].insert(pos);

		if (oldBefore != -1) {
			updateNeigh(last, oldBefore);
		}

		if (oldNext != 1e8) {
			updateNeigh(last, oldNext);
		}

		updateNeigh(val, pos);

		int newBefore = getPred(val, pos); 
		int newNext = getSucc(val, pos);

		if (newBefore != -1) {
			updateNeigh(val, newBefore);
		}

		if (newNext != 1e8) {
			updateNeigh(val, newNext);
		}
	};

	for (int i = 0; i < n; i++) {
		update(x[i], i);
	}

	for (auto [op, first, second]: queries) {
		if (op == 1) {
			int k = first, u = second;
			update(u, k - 1);
		} else {
			int a = first - 1, b = second - 1;
			auto result = seg.query(a, b + 1);
			if (result.first >= a && result.first <= b) {
				cout << "NO" << endl;
				continue;
			}
			if (result.second >= a && result.second <= b) {
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
		}
	}

	return 0;
}
