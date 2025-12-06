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
	solution();
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	i64 a[n];
	for(i32 i = 0; i < n; i++) {
		cin >> a[i];
	}

	i64 counter = 0;
	i64 use = 1;
	for(i32 i =0 ;i < n; i++) {
		if(use) {
			use--;
			use = max(a[i] - 1, use);
			counter++;

		}else{
			break;;
		}
	}
	cout << counter << endl;

	
}
