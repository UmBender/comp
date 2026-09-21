#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"

constexpr int mod = 998244353;

template<class S, S(*op)(S, S), S(*e)(), class U, S (*mapping)(U, S),
	U (*compose)(U, U), U(*id)()>
struct LazySegtree {
	vector<S> t;
	vector<U> d;
	int n;
	LazySegtree(int N): t(4 * N, e()), d(4 * N, id()), n(N) {}
	void applyNode(int i, U u) {
		t[i] = mapping(u, t[i]);
		d[i] = compose(u, d[i]);
	}
	void push(int i ) {
		applyNode(i << 1, d[i]);
		applyNode(i << 1 | 1, d[i]);
		d[i] = id();
	}
	void pull(int i) { t[i] = op(t[i << 1], t[i << 1 | 1]); }
	void set(int j, S val) { set(j, val, 0, n, 1); }
	void set(int j, S val, int tl, int tr, int i) {
		if(tl + 1 == tr) {
			t[i] = val;
			d[i] = id();
			return;
		}
		push(i);
		int tm = (tl + tr) / 2;
		if (j < tm) set(j, val, tl, tm, i << 1);
		else set(j, val, tm, tr, i  << 1 | 1);
		pull(i);
	}
	void apply(int l, int r, U u) { apply(l, r, u, 0, n, 1); }
	void apply(int l, int r, U u, int tl, int tr, int i) {
		if (r <= tl || tr <= l) return;
		if (l <= tl && tr <= r) return applyNode(i, u);
		push(i);
		int tm = (tl + tr) / 2;
		apply(l, r, u, tl, tm, i << 1);
		apply(l, r, u, tm, tr, i << 1 | 1);
		pull(i);
	}
	S sum(int l, int r) { return sum(l, r, 0, n, 1); }
	S sum(int l, int r, int tl, int tr, int i) {
		if (r <= tl || tr <= l) return e();
		if (l <= tl && tr <= r) return t[i];
		push(i);
		int tm = (tl + tr) / 2;
		return op(sum(l, r, tl, tm, i << 1), sum(l, r, tm, tr, i << 1 | 1));
	}

};

struct SumSquare {
	int square, lin, len;
};
struct IncSquare {
	int val;
};

SumSquare squareOp(SumSquare f, SumSquare s) {
	return SumSquare {
		(f.square + s.square) % mod, (f.lin + s.lin) % mod, f.len + s.len
	};
}

SumSquare squareE() {
	return SumSquare {
		0, 0, 0
	};
}
SumSquare squareMap(IncSquare inc, SumSquare s) {
	int first = (2ll * inc.val % mod) * s.lin % mod;
	int second = (inc.val * inc.val % mod) * s.len % mod;
	return SumSquare {
		(s.square + first + second) % mod,
			(s.lin + (inc.val * s.len % mod) % mod) % mod,
			s.len
	};
}


IncSquare squareComp(IncSquare f, IncSquare s) {
	return IncSquare {
		(f.val + s.val) % mod
	};
}

IncSquare squareId() {
	return IncSquare {
		0
	};
}


constexpr int inv2 = mod / 2 + 1;
using SegtreeSquare = LazySegtree<SumSquare, squareOp, squareE, IncSquare, squareMap, squareComp, squareId>;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	SegtreeSquare st(n);
	for (int i = 0; i < n; i++) {
			auto first = SumSquare { 0, 0, 1 };
			st.set(i, first);
	}
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		x = (x % mod + mod) % mod;
		l--;
		auto first = IncSquare { x };
		st.apply(l, r, first);
		auto node = st.sum(l, r);
		int squared = node.square;
		int sum = node.lin;
		int result = ((sum * sum % mod) + mod - squared) % mod;
		cout << (result * inv2 % mod) << endl;
	}
	
	return 0;
}
