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

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i64 n;
	cin >> n;
	vector<i32> parts;
	i64 temp = n;
	while(temp) {
		parts.push_back(temp % 10);
		temp /= 10;
	}
	sort(parts.begin(), parts.end());
	function<i64(i64, i64)> dfs;

	dfs = [&](i64 first, i64 second) -> i64 {
		if(parts.empty()) {
			return first * second;
 		}
		i64 actual = parts.back();
		parts.pop_back();
		i64 tempfirst = first * 10 + actual;
		i64 tempsecond = second * 10 + actual;
		i64 mmax = dfs(tempfirst, second);
		mmax = max(dfs(first, tempsecond), mmax);
		parts.push_back(actual);
		return mmax;
	};
	i64 result = dfs(0,0);
	cout << result << endl;

	return 0;
}
