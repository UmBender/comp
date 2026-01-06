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
	string s;
	cin >> s;
	map<char, i32> positions;
	set<i32> pos;
	i32 mmin = INT32_MAX;
	i32 number = 0;
	{
		set<char> uniques;
		for (auto i: s) {
			if (!uniques.count(i)) {
				uniques.insert(i);
			}
		}
		number = uniques.size();
	}

	for (i32 i = 0; i < n; i++) {
		if (positions.count(s[i])) {
			pos.erase(positions[s[i]]);
		}
		pos.insert(i);
		positions[s[i]] = i;
		if (positions.size() == number) {
			auto it = pos.begin();
			i32 left = *it;
			mmin = min(mmin, i - left + 1);
		}
	}
	cout << mmin << endl;

	
	return 0;
}
