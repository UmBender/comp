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
	i32 n;
	cin >> n;
	vector<i64> p(n + 1);
	for(i32 i = 1; i <= n; i++) {
		cin >> p[i];
	}

	vector<bool> visited(n + 1);
	i64 counter = 0;
	for(i32 i = 1; i <= n;i ++) {
		if(!visited[i]) {
			i64 length = 0;
			i64 current = i;
			while(!visited[current]){
				visited[current] = true;
				current = p[current];
				length++;
			}
			if(length > 1) {
				counter += (length * (length - 1))/2;
			}
		}
	}
	cout << counter << endl;
}
