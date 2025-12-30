# include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;
// debug stuff, no need to type at first
void PRINT(auto x) { cerr << '\t' << x << endl; }
void PRINT(const char *name, auto... x) {
	cerr << "DEBUG> "<< name << " = [" << endl;
	(PRINT(x), ...);
	cerr << ']' << endl;
}
# define DEBUG(...) PRINT(#__VA_ARGS__, __VA_ARGS__)
// #define int i64

const i64 MOD = 998244353;

struct BIT {
	i32 n;
	vector<i64> tree;
	BIT(i32 _n): n(_n + 1), tree(n) {}
	void update(i32 pos, i64 value) {
		for(pos++; pos < n; pos += (-pos&pos)) {
			tree[pos] += value;
			tree[pos] %= MOD;
		}
	}
	inline i64 query(i32 right) {
		i64 acc = 0;
		for(right++; right > 0; right -= (-right&right)) {
			acc += tree[right];
			acc %= MOD;
		}
		return acc;
	}
	i64 query(i64 left, i64 right) {
		i64 first = query(right);
		i64 second = query(left - 1);

		return (first - second + MOD) % MOD;
	}
};

i64 fast_exp(i64 x, i64 y) {
	if(y == 0) {
		return 1;
	}
	i64 temp = fast_exp(x, y / 2);
	i64 acc = temp * temp;
	acc %= MOD;
	if(y & 1) {
		acc *= x;
	}
	acc %= MOD;
	return acc;

}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	const i64 mod_inv = (MOD + 1) / 2;
	i32 n;
	cin >> n;
	vector<i64> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<i64> rest;
	{
		set<i64> nums(a.begin(), a.end());
		rest = vector<i64>(nums.begin(), nums.end());
	}
	map<i64,i64> mp;
	i64 last = 0;
	for(auto i: rest) {
		mp[i] = last;
		++last;
	}

	i64 count = 0;
	BIT len(last + 10);

	for(i64 i = 0; i < n; i++) { 
		i64 temp = len.query(0,mp[a[i]]);
	   	temp *= fast_exp(2, i);
		count += temp;
		count %= MOD;
		len.update(mp[a[i]], fast_exp(mod_inv, i + 1));
	}
	cout << count << endl;
	
	return 0;
}
