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

void solution();
void setIO(string name = "") {
	if(!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("countcross");
	solution();
	return 0;
}

struct Road {
	pair<i32,i32> first, second;
	Road(pair<i32,i32> f={0,0}, pair<i32,i32> s={0,0}):first(f), second(s) {}
};

/*
bool operator<(const Road&  first, const Road&  second) {
	if(first.first == second.first) {
		return first.second < second.second;
	}
	return first.first < second.first;
}
*/

bool operator<(Road const first, Road const second) {
	if(first.first == second.first) {
		return first.second < second.second;
	}
	return first.first < second.first;
}
bool operator==(Road& first, Road& second) {
	return first.first == second.first && first.second == second.second;
}


void solution() {
	i32 n, k, r;
	cin >> n >> k >> r;
	vector<vector<i32>> grid(n, vector<i32>(n));
	set<Road> roads;
	for(i32 rr = 0; rr < r; rr++) {
		i32 r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--,c1--,r2--,c2--;
		Road road1({r1,c1}, {r2, c2}), road2({r2,c2},{r1,c1});
		roads.insert(road1);
		roads.insert(road2);
	}
	set<pair<i32,i32>> cows;
	for(i32 kk = 0; kk < k; kk++) {
		i32 r,c;
		cin >> r >> c;
		r--,c--;
		cows.insert(make_pair(r,c));
	}

	if(r == 0) {
		cout << 0 << endl;
		return;
	}

	if(k == 0) {
		cout << 0 << endl;
		return;
	}

	function<void(pair<i32,i32>, pair<i32,i32>, i32 actual)> dfs;
	dfs = [&](pair<i32,i32> actual, pair<i32,i32> last, i32 group) {
		auto [ra,ca] = actual;
		if(ra < 0 || ra >= n || ca < 0 || ca >= n) {
			return;
		}
		Road road(actual, last);
		if(roads.count(road)) {
			return;
		}
		if(grid[ra][ca] != 0) {
			return;
		}

		grid[ra][ca] = group;

		dfs({ra-1, ca}, actual, group);
		dfs({ra, ca-1}, actual, group);
		dfs({ra+1, ca}, actual, group);
		dfs({ra, ca+1}, actual, group);
	};
	i32 c_group = 1;
	for(i32 i =0; i < n;i++){ 
		for(i32 j= 0; j < n;j++) {
			pair<i32,i32> actual = {i, j};
			if(!grid[i][j]) {
				dfs(actual,actual,c_group++);
			}
		}
	}


	vector<i32> counter(c_group);
	for(auto [r,c]: cows) {
		counter[grid[r][c]]++;
	}

	i64 rest = k;
	i64 acc = 0;
	for(auto count: counter) {
		rest -= count;
		acc += rest * count;
	}
	//cout << "group_size: " << distinct.size() << endl;
	cout << acc << endl;
}
