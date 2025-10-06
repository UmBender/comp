#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	int n;
	cin >> n;
	set<pair<pair<int, int>, int>> elements;
	vector<bool> is_inside(n), owner(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		elements.insert({{a, -b}, i});
	}
	map<int, pair<int, int>> intervals;
	for (auto [interval, id] : elements) {
		auto [begin, end] = interval;
		end = -end;
		auto minimal = intervals.upper_bound(end - 1);
		if (minimal == intervals.end()) {
			intervals[end] = {begin, id};
			continue;
		}
		int last = -1;
		vector<int> removes;
		for (auto actual = minimal; actual != intervals.end(); actual++) {
			if (last != -1) { removes.push_back(last); }
			auto [int_end, pudim] = *actual;
			auto [int_begin, int_id] = pudim;
			if (int_end == end && begin == int_begin) {
				is_inside[int_id] = true;
				owner[id] = true;
			}
			is_inside[id] = true;
			owner[int_id] = true;
			last = int_end;
		}
		for (auto i : removes) { intervals.erase(i); }
		intervals[end] = {begin, id};
	}
	for (int i = 0; i < n; i++) { cout << (int)owner[i] << " "; }
	cout << endl;
	for (int i = 0; i < n; i++) { cout << (int)is_inside[i] << " "; }
	cout << endl;
}
