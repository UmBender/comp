#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

struct Value {
	i32 value, left, right;
	Value(i32 v = 0, i32 l = 0, i32 r = 0) : value(v), left(l), right(r) {}
};

Value op(Value a, Value b) {
	if (!a.left) {
		return b;
	}
	if (!b.left) {
		return a;
	}

	vector<i32> points = {a.left, a.right, b.left, b.right};
	ranges::sort(points);
	i32 value = points[2] - points[1];
	if (a.value) {
		value = gcd(value, a.value);
	}
	if (b.value) {
		value = gcd(value, b.value);
	}

	return Value(value, points[0], points[3]);
}

Value e() { return Value(); }

template <class S, S (*op)(S, S), S (*e)()> struct Segtree {
	vector<S> t;
	int n;
	Segtree(int N) : t(2 * N, e()), n(N) {}
	void set(int i, S value) {
		t[i += n] = value;
		for (i >>= 1; i; i >>= 1)
			t[i] = op(t[i << 1], t[i << 1 | 1]);
	}
	S query(int l, int r) {
		S al = e(), ar = e();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1)
				al = op(al, t[l++]);
			if (r & 1)
				ar = op(t[--r], ar);
		}
		return op(al, ar);
	}
};

using Seg = Segtree<Value, op, e>;

std::vector<i32> sieve(i32 n) {
	std::vector<i32> divisors(n);
	divisors[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!divisors[i]) {
			divisors[i] = 2;
		} else {
			continue;
		}
		for (int j = i * 2; j < n; j += i) {
			int counter = 1;
			int temp = j;
			while (temp % i == 0) {
				counter++;
				temp /= i;
			}
			if (divisors[temp] == 0) {
				continue;
			}
			divisors[j] = divisors[temp] * counter;
		}
	}
	return divisors;
}

auto divisors = sieve(1000100);
void solution();
i32 main() {
	cin.tie(0)->sync_with_stdio(0);

	i32 t;
	cin >> t;
	while (t--) {
		solution();
	}

	return 0;
}

void solution() {
	i32 n, q;
	cin >> n >> q;
	vector<i64> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}

	Seg s = Seg(n + 1);
	for (i32 i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			s.set(i, Value(0, i + 1, i + 1));
		}
	}

	auto query = [&]() -> i32 {
		Value v = s.query(0, n - 1);
		if (v.left == 0) {
			return n;
		}
		i32 result = v.left;
		if (v.value) {
			result = gcd(result, v.value);
		}
		return divisors[result];
	};

	auto update = [&](i32 pos, i32 value) {
		a[pos] = value;
		if (pos > 0) {
			s.set(pos - 1, Value());
			if (a[pos - 1] > a[pos]) {
				s.set(pos - 1, Value(0, pos, pos));
			}
		}
		if (pos + 1 < n) {
			s.set(pos, Value());
			if (a[pos] > a[pos + 1]) {
				s.set(pos, Value(0, pos + 1, pos + 1));
			}
		}
	};

	cout << query() << '\n';
	for (i32 qq{0}; qq < q; qq++) {
		i32 p, v;
		cin >> p >> v;
		p--;
		update(p, v);
		cout << query() << '\n';
	}
}
