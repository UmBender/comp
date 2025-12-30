#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();
	return 0;
}


struct BIT {
	vector<i32> t;
	i32 n;
	BIT(i32 s): t(s + 1), n(s + 1) {}
	void update(i32 pos, i32 delta) {
		pos++;
		for(; pos < n; pos+=(-pos&pos)) {
			t[pos] += delta;
		}
	}

	inline i32 query(i32 right) {
		i32 acc = 0;
		right++;
		for(; right > 0; right -=(-right&right)) {
			acc += t[right];
		}
		return acc;
	}
	i32 query(i32 left, i32 right) {
		i32 first = query(right);
		i32 second = query(left - 1);
		return first - second;
	}
};

void solution() {
	i32 n, q; 
	cin >> n >> q;
	vector<i64> x(n);
	for(i32 i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<pair<i32,i32>> queries(q);
	for(auto &[x,y]: queries) {
		cin >> x >> y;
		x--, y--;
	}
	vector<pair<i32,i32>> rev(q);
	for(i32 i = 0; i < q; i++) {
		auto [f,s] = queries[i];
		rev[i] = {s, f};
	}
	sort(rev.begin(), rev.end());
	map<pair<i32,i32>, i32> ans;
	i32 last = 0;
	map<i64,i64> positions;
	BIT bit(n + 1);

	for(auto [b, a]: rev) {
		while(last <= b) {
			i32 actual_pos = x[last];
			if (positions.count(x[last])) {
				bit.update(positions[x[last]], -1);
			}
				positions[x[last]] = last;
			bit.update(last, 1);
			last++;
		}
		i32 result = bit.query(a, b);
		ans[make_pair(a,b)] = result;
	}
	for(auto qq: queries) {
		cout << ans[qq] << endl;
	}

}
