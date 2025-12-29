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
	string s;
	cin >> s;
	bool first = false, second = false;
	string first_check = "2026", second_check = "2025";
	for(i32 i = 0; i < n - 3; i++) {
		bool temp_first = true;
		for(i32 j = 0; j < 4; j++) {
			temp_first &= (first_check[j] == s[i + j]);
		}
		first |= temp_first;

		bool temp_second = true;
		for(i32 j = 0; j < 4; j++) {
			temp_second &= (second_check[j] == s[i + j]);
		}

		second |= temp_second;
	}
	cout << ((first || !second) ? "0" : "1") << endl;

	
}
