#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


signed main() {
	auto solve = [&](string s) -> int {
		string remove = "ABC";
		int n = s.size();
		vector<char> stack;
		for (int i = n - 1; i >= 0; i--) {
			stack.push_back(s[i]);
			if (stack.back() == 'A') {
				for (char c: remove) {
					if (stack.empty()) {
						break;
					}
					if (stack.back() == c) {
						stack.pop_back();
					} else {
						break;
					}
				}
			}
		}
		return stack.size(); 
	};
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
