#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() {
	int t;
	cin >> t;
	while (t--) { solution(); }
}

inline auto query(int pos, int mask) -> bool {
	cout << "? " << pos << " " << mask << endl;
	cout.flush();
	bool opt;
	cin >> opt;
	return opt;
}

void solution() {
	int n;
	cin >> n;
	vector<int> positions;
	vector<int> values;
	int acc = 0;
	for (int i = 1; i < n; i++) { positions.push_back(i); }
	for (int i = 1; i <= n; i++) { values.push_back(i); }
	for (int pot = 0; pot <= 20; pot++) {
		vector<int> ones;
		vector<int> zeros;
		int counters[2] = {0, 0};
		for (auto pos : positions) {
			bool result = query(pos, (1ll << pot));
			if (result) {
				ones.push_back(pos);
			} else {
				zeros.push_back(pos);
			}
		}
		for (int value : values) { counters[(value >> pot) & 1]++; }
		vector<int> new_values;
		int compare = (counters[0] == zeros.size()) ? 1 : 0;
		for (int value : values) {
			if (((value >> pot) & 1) == compare) {
				new_values.push_back(value);
			}
		}
		values = new_values;
		if (counters[0] == zeros.size()) {
			positions = ones;
			acc += (1ll << pot);
		} else {
			positions = zeros;
		}
		if (positions.empty()) {
			if (acc == 0) { acc |= (1ll << (pot + 1)); }
			break;
		}
	}
	cout << format("! {}", acc) << endl;
	cout.flush();
}
