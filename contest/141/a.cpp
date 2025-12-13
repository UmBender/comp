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
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	while(s.size() < n) {
		s += "o";
	}
	reverse(s.begin(), s.end());
	
	cout << s << endl;

}
