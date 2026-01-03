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
	i32 n, p;
	cin >> n >> p;
	vector<i32> a(n);
	for (i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	i32 counter = 0;
	for(i32 i = 0; i < n; i++) {
		if(a[i] < p) {
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
}

