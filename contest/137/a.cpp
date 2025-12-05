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
	i32 n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	i32 rest = 0;
	i32 sleep = 0;
	for(i32 i = 0; i < n; i++) {
		if(s[i] == '1') {
			rest = k;
		}else{
			if(rest) {
				rest--;
			}else{
				sleep++;
			}
		}

	}
	cout << sleep << endl;

}
