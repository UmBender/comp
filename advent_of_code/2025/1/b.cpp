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


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	i64 actual = 50;
	i32 counter = 0;	
	while(n--){
		string a;
		cin >> a;
		i64 direction;
		if(a[0] == 'R') {
			direction = 1;
		}else{
			direction = -1;
		}
		a.erase(a.begin());
		i64 result = stoll(a);
		for(i64 i = 0; i < result; i++) {
			actual += direction;
			actual += 100;
			actual %= 100;
			if(actual == 0) {
				counter ++;
			}

		}
	}
	cout << counter << endl;
	return 0;
}
