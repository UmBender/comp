#include<bits/stdc++.h>
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
	vector<i64> a(n);
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	i32 maximal = a.front();
	i32 rest = a[1] - a[0]; 
	if(rest > a[0]) {
		cout << rest << endl;
		return;
	}
	cout << maximal << endl;
	
	
}
