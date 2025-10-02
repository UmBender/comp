#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	vector<pair<int, int>> ab(m);
	vector<int> pos(n + 2);
	for (auto &i : ab) {
		cin >> i.first >> i.second;
		i.first--;
		i.second--;
	}
	for (int i = 0; i < n; i++) { pos[x[i]] = i; }
	int counter = 1;
	int last = -1;
	pos[0] = -1;
	pos[n + 1] = n;
	for (int i = 1; i <= n; i++) {
		if (pos[i] > last) {
			last = pos[i];
		} else {
			last = pos[i];
			counter++;
		}
	}

	auto check_pred = [&](int o_p, int n_p, int val) -> int {
		if (o_p >= pos[val - 1] && n_p <= pos[val - 1]) { return 1; }
		if (o_p <= pos[val - 1] && n_p >= pos[val - 1]) { return -1; }
		return 0;
	};

	auto check_succ = [&](int o_p, int n_p, int val) -> int {
		if (o_p >= pos[val + 1] && n_p <= pos[val + 1]) { return -1; }
		if (o_p <= pos[val + 1] && n_p >= pos[val + 1]) { return 1; }
		return 0;
	};

	for (int qq = 0; qq < m; qq++) {
		int value_first = x[ab[qq].first];
		int value_second = x[ab[qq].second];
		swap(x[ab[qq].first], x[ab[qq].second]);
		swap(pos[value_first], pos[value_second]);
		if (abs(value_first - value_second) == 1) {
			if (value_first > value_second) {
				swap(value_first, value_second);
				swap(ab[qq].first, ab[qq].second);
			}

			counter += check_succ(ab[qq].first, ab[qq].second, value_first);
			counter += check_pred(ab[qq].first, ab[qq].second, value_first);
			counter += check_succ(ab[qq].second, ab[qq].first, value_second);
		} else {
			counter += check_pred(ab[qq].first, ab[qq].second, value_first);
			counter += check_succ(ab[qq].first, ab[qq].second, value_first);
			counter += check_pred(ab[qq].second, ab[qq].first, value_second);
			counter += check_succ(ab[qq].second, ab[qq].first, value_second);
		}
		cout << counter << endl;
	}

	return 0;
}
