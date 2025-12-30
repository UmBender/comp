#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

bool cless(vector<string> &actual, vector<string> &next) {
	for (i32 i = 0; i < actual.size(); i++) {
		if (actual[i] < next[i]) {
			return true;
		}
		if(actual[i] > next[i]) {
			return false;
		}
	}
	return false;
}

bool ans_check(vector<string> &actual, vector<pair<string, string>> &rel) {
	i32 counter = 0;
	for (i32 i = 0; i < actual.size() - 1; i++) {
		for (i32 j = 0; j < rel.size(); j++) {
			auto [first, second] = rel[j];
			if (actual[i] == first && actual[i + 1] == second) {
				counter++;
			}
			if (actual[i] == second && actual[i + 1] == first) {
				counter++;
			}
		}
	}
	if (counter == rel.size()) {
		return true;
	}
	return false;
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	i32 n;
	cin >> n;
	vector<pair<string, string>> restrictions;
	for (int i = 0; i < n; i++) {
		string cow1 = "";
		string cow2 = "";
		for (int j = 0; j < 6; j++) {
			string word;
			cin >> word;
			cow1 = cow1.empty() ? word : cow1;
			cow2 = word;
		}
		restrictions.emplace_back(cow1, cow2);
	}
	vector<string> base = {"Bessie", "Buttercup", "Belinda", "Beatrice",
		"Bella",  "Blue",      "Betsy",   "Sue"};
	sort(base.rbegin(), base.rend());

	vector<string> ans = base;
	reverse(base.begin(), base.end());
	do {
		vector<string> actual = base;
		if (ans_check(actual, restrictions)) {
			if (cless(actual, ans)) {
				swap(ans, actual);
			}
		}
	} while (next_permutation(base.begin(), base.end()));

	for(i32 i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
