# include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;
// debug stuff, no need to type at first
void PRINT(auto x) { cerr << '\t' << x << endl; }
void PRINT(const char *name, auto... x) {
	cerr << "DEBUG> "<< name << " = [" << endl;
	(PRINT(x), ...);
	cerr << ']' << endl;
}
# define DEBUG(...) PRINT(#__VA_ARGS__, __VA_ARGS__)
// #define int i64
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	vector<i64> t(n);
	vector<vector<i32>> ka(n);
	for (i32 i = 0; i < n; i++) {
		cin >> t[i];
		i32 k;
		cin >> k;
		ka[i] = vector<i32>(k);
		for (i32 j = 0; j < k; j++) {
			cin >> ka[i][j];
			ka[i][j]--;
		}
	}
	set<i32> learned;
	set<i32> not_learned;
	i64 time = 0;
	not_learned.insert(n-1);
	while (not_learned.size()) {
		i32 actual = *not_learned.begin();
		not_learned.erase(actual);
		learned.insert(actual);
		time += t[actual];
		for (i32 next: ka[actual]) {
			if (learned.count(next)) {
				continue;
			}
			if (not_learned.count(next)) {
				continue;
			}
			not_learned.insert(next);
		}
	}
	cout << time << endl;


	return 0;
}
