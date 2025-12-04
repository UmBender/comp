#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

i32 grid[30][30];
i32 temp[30][30];


void show_coord(tuple<i32,i32,i32,i32> x) {
	auto [l, r, u, d] = x;
	cout << "l: " << l << " r: " << r << " u: " << u << " d: " << d << endl;
}
void setIO(string name = "") {
	if(!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("where");
	i32 n;
	cin >> n;
	for(i32 i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for(i32 j = 0; j < n; j++){ 
			grid[i][j] = temp[j];
		}
	}
	auto is_valid =[&](i32 l, i32 r, i32 u, i32 d) -> i32 {
		map<i32,i32> counter;
		for(i32 i = l; i <= r; i++) {
			for(i32 j = u; j <= d; j++) {
				counter[grid[j][i]]++;
			}
		}
		return counter.size();
	};
	set<tuple<i32,i32,i32,i32>> ok;

	for(i32 i = 0; i < n; i++) {
		for(i32 j = 0; j < n; j++) {
			for(i32 k = i; k < n; k++) {
				bool added = false;

				for(i32 l = j; l < n; l++) {
					i32 result = is_valid(j, l, i, k);
					if(result == 2) {
						ok.insert({j,l,i,k});
					}else if(result > 2) {
						break;
					}
				}	
			}
		}
	}


	auto clear_temp = [&]() {
		for(i32 i = 0; i < n; i++) {
			for(i32 j= 0; j < n;j++) {

				temp[i][j]= 0;

			}
		}
	};


	function<void(i32,i32, tuple<i32,i32,i32,i32>, i32, i32)> dfs;
	dfs = [&](i32 v,i32 h, tuple<i32,i32,i32,i32> p, i32 g, i32 c) {
		auto[l,r,u,d] =p;
		if(v > d || v < u || h < l || h > r) {
			return;
		}
		if(grid[v][h] != c) {
			return;
		}
		if(temp[v][h]) {
			return;
		}
		temp[v][h] = c;
		dfs(v-1, h, p, g, c);
		dfs(v+1, h, p, g, c);
		dfs(v, h-1, p, g, c);
		dfs(v, h+1, p, g, c);
	};

	set<tuple<i32,i32,i32,i32>> result;
	for(auto x: ok) {
		auto [l,r,u,d] = x;
		map<i32,i32> disjoint_counter;
		clear_temp();
		i32 g = 1;
		for(i32 i =l; i<= r;i++){ 
			for(i32 j = u; j <= d; j++) {
				if(!temp[j][i]) {
					dfs(j,i,x, ++g, grid[j][i]);
					disjoint_counter[grid[j][i]]++;
				}
			}	
		} 
		auto [s,first] = *disjoint_counter.begin();
		auto [t,second] = *disjoint_counter.rbegin();
		if(first == 1 &&  second >= 2 && disjoint_counter.size() == 2) {
			result.insert(x);
			continue;
		}
		if(first >= 2 && second == 1 && disjoint_counter.size() == 2) {
			result.insert(x);
			continue;
		}
	}


	ok = result;
	set<tuple<i32,i32,i32,i32>> must_remove;
	for(auto [l,r,u,d]: ok) {
		for(i32 i = 0; i <= l; i++) {
			for(i32 j = n-1; j >= r; j--){
				for(i32 k = 0; k <= u; k++){
					for(i32 m = n-1; m >= d; m--){
						tuple<i32,i32,i32,i32> bigger = {i,j, k,m},
							actual =  { l, r, u, d};

						if(actual == bigger) {
							continue;
						}
						if(ok.count(bigger)) {
							must_remove.insert(actual);
						}


					}
				}
			}
		}
	}

	for(auto i: must_remove) {
		ok.erase(i);
	}
	result = ok;


	cout << result.size() << endl;
	

	

	return 0;
}
