#include <bits/stdc++.h>
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
i32 winner(char first, char second) {
	if(first == second) {
		return 0;
	}
	if(first == 'G' && second == 'P') {
		return -1;
	}
	if(first == 'P' && second == 'G') {
		return 1;
	}
	if(first == 'C' && second == 'P') {
		return 1;
	}
	if(first == 'P' && second == 'C') {
		return -1;
	}
	if(first == 'G' && second == 'C') {
		return 1;
	}
	if(first == 'C' && second == 'G') {
		return -1;
	}
	return 0;
}
i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n, m;
	cin >> n >> m;
	vector<string> a(2 * n);
	for (i32 i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	vector<pair<i32,i32>> actual(2 * n);
	for (i32 i = 0; i < 2 * n; i++) {
		actual[i] = {0, i};
	}
	vector<pair<i32,i32>> next(2 * n);
	for(i32 k = 0; k < m; k++) {
		for(i32 i = 0; i < n; i++) {
			i32 first = i * 2, second = i * 2 + 1;
			i32 pfirst = actual[i * 2].second, psecond = actual[i * 2 + 1].second;

			if(a[pfirst][k] == a[psecond][k]) {
				next[first] = actual[first];
				next[second] = actual[second];
				continue;
			}
			i32 result = winner(a[pfirst][k], a[psecond][k]);
			if(result == -1) {
				swap(first,second);
			}
			next[first] = actual[first];
			next[first].first--;
			next[second] = actual[second];
					
		}
		sort(next.begin(), next.end());
		swap(next, actual);
	}
	
	for (i32 i = 0; i < 2*n; i++) {
		cout << actual[i].second  + 1 << endl;
	}
	
	return 0;
}

