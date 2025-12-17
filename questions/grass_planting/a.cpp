#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();
void setIO(string name = "") {
	if(name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("planting");
	solution();
	return 0;
}

void solution() {
	i32 n;
	cin >> n;
	vector<vector<i32>> adj(n + 1);
	for(i32 i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(n ==1) {
		cout << 1 << endl;
	}	
	if(n == 2) {
		cout << 2 << endl;
	}

	vector<i32> counter(n + 1);

	auto check = [&](i32 node) -> i32 {
		i32 colors = 1;
		i32 second_level =  adj[node].size();
		i32 mmax = 0;
		for(i32 next: adj[node]) {
			mmax = max(mmax, (i32)adj[next].size() -1);
		}
		i32 needed = mmax - second_level - 1;
		colors += second_level;
		return colors;
	};

	i32 mmax = 0;
	for(i32 i = 1; i <= n; i++) {
		mmax = max(mmax, check(i));
	}
	cout << mmax << endl;
}
