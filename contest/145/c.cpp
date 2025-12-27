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
	solution();
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	vector<i64> a(n);
	for(auto &i: a) {
		cin >> i;
	}
	vector<i64> elements;
	for(i32 i = 0; i < n; i ++) {
		elements.push_back(a[i]);
		if(elements.size() >= 4) {
			i32 pos = elements.size() - 1;
			i32 last = elements.back();
			i32 counter = 0;
			for(i32 j = 0; j < 4; j++) {
				counter += elements[pos-j] == last;
			}
			if(counter == 4) {
				for(i32 j = 0; j < 4; j++) {
					elements.pop_back();
				}
			}

		}
	}
	cout << elements.size() << endl;
}
