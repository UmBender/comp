#include <bits/stdc++.h>
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

	solution();
	return 0;
}

void solution() {
	i32 n, m;
	cin >> n >> m;
	set<pair<i32,i32>> used;
	i32 counter = 0;
	for(i32 mm = 0; mm < m; mm++) {
		i32 r,c;
		cin >> r >> c;
		bool okay = true;
		for(i32 i = 0; i < 2; i++) {
			for(i32 j = 0; j < 2; j++) {
				pair<i32,i32> actual = make_pair(r + i, c + j);
				if(used.count(actual)) {
					okay = false;
				}
			}
		}
		if(okay) {
			counter ++;
			for(i32 i = 0; i < 2; i++) {
				for(i32 j = 0; j < 2; j++) {
					pair<i32,i32> actual = make_pair(r + i, c + j);
					used.insert(actual);
				}
			}

		}

	}
	cout << counter << endl;

}
