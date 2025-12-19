#include<bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 t;
	cin >> t;
	while(t--) {
		solution();
	}
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	vector<string> a(n);
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s;
	for(i32 i = 0; i < n; i++) {
		string first = a[i] + s, second = s + a[i];
		s = min(first, second);
	}
	cout << s << endl;

}


