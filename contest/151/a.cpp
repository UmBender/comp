#include<bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int rest = n;
	int last = n % 10;
	bool okay = true;
	for (int i = 0; i < 3; i++) {
		if (last != rest % 10) {
			okay = false;
			break;
		}
		rest /= 10;
	}
	if (okay) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;

	}

	return 0;
}
