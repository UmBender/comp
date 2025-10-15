#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solution();
signed main() {
	solution();
	return 0;
}
void solution() {
	int n;
	cin >> n;
	vector<pair<int, int>> ab(n);
	map<int, vector<pair<int, int>>> ending;
	for(auto &[a,b]: ab) {
		cin >> a >> b;
	}
	for (int i = 0; i < n; i++) {
		ending[ab[i].first].push_back({ab[i].second, i});
	}

	int new_room = 0;
	queue<int> free_rooms;
	vector<int> hosp(n);
	std::priority_queue<pair<int, int>, std::vector<pair<int, int>>,
	                    std::greater<pair<int, int>>>
	    pq;
	for (auto actual : ending) {
		while (!pq.empty() && pq.top().first < actual.first) {
			free_rooms.push(pq.top().second);
			pq.pop();
		}
		while (free_rooms.size() < actual.second.size()) {
			free_rooms.push(new_room + 1);
			new_room++;
		}

		for (auto nint : actual.second) {
			int actual_room = free_rooms.front();
			free_rooms.pop();
			hosp[nint.second] = actual_room;
			pq.push({nint.first, actual_room});
		}
	}
	cout << new_room << endl;
	for (int i = 0; i < n; i++) { cout << hosp[i] << " "; }
	cout << endl;
}
