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


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	set<i64> nums;
	auto convert = [](i64 value) {
		i32 acc = 0;
		i64 temp = value;
		while (temp) {
			i64 decimal = temp % 10;
			acc += decimal * decimal;
			temp /= 10;
		}
		return acc;
	};
	i64 n;
	cin >> n;
	while(!nums.count(n) && n != 1) {
		nums.insert(n);
		i64 result = convert(n);
		n = result;
	}
	if (n == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

