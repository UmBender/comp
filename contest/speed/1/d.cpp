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
	i32 n;
	cin >> n;
	vector<i64> a(n), b(n);
	for(i32 i = 0; i < n; i++) {
		i32 temp;
		cin >> a[i] >> temp;
		b[i] = temp + a[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	map<i32,i32> acc;
	i32 i = 1, j = 0;
	i32 counter = 1;
	i32 last = a.front();
	while(i < n && j < n) {
		if(a[i] <= b[j]) {
			acc[counter] += a[i] - last;
			counter++;
			last = a[i];
			i++;
		}else{
			acc[counter] += b[j] - last;
			counter--;
			last = b[j];
			j++;
		}
	}
	while(j < b.size()) {
		acc[counter] += b[j] - last;
		counter--;
		last = b[j];
		j++;
	}
	for(i32 i = 1; i <= n; i++) {
		cout << acc[i] << " \n"[i==n];
	}
	return 0;
}
