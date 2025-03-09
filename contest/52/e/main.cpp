//#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)


#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
template<class T>
void show(vector<vector<T>> &grid) {
	for(auto &i: grid) {
		for(auto &j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
}



void solution() {
	int r,c,n;
	cin >> r >> c >> n;
	vector<vector<int>> grid(r,vector<int>(c));
	for(auto &i: grid) {
		for(auto &j: i) {
			cin >> j;
		}
	}
	vector<vector<char>> neu(r, vector<char>(c));
	for(int i = 0; i < r; i ++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] == -1) {
				neu[i][j] = '#';
			}else {
				int counter = 0;
				if(i > 0 && grid[i-1][j]> grid[i][j] && grid[i-1][j] != -1) {
					counter++;
				}
				if(i < r-1 && grid[i+1][j] > grid[i][j] && grid[i+1][j] != -1) {
					counter++;
				}
				if(j > 0 && grid[i][j-1] < grid[i][j] && grid[i][j-1] != -1) {
					counter++;
				}
				if(j < c-1 && grid[i][j+1] < grid[i][j] && grid[i][j+1] != -1) {
					counter++;
				}
				if(counter == 4) {
					neu[i][j]='y';
				}else{
					neu[i][j]='n';
				}
			}
		}
	}

	vector<vector<vector<int>>> min_sol(r, vector<vector<int>>(c, vector<int>(n+1,MAX_INT)));
	for(int i = 0; i < r; i++) {
		if(neu[i][0] == '#') {
			continue;
		}
		min_sol[i][0][0] = grid[i][0];
	}
	for(int j = 0; j < c-1;j++) {
		for(int i = 0; i < r; i++) {
			if(neu[i][j] == '#') {
				continue;
			}
			for(int l = -1; l <= 1; l++) {
				if(i + l >= 0 && i+l < r && neu[i+l][j+1] != '#') {
					int is_passes = neu[i+l][j+1]=='y' ? 1: 0;
					for(int k = 0; k+ is_passes <= n; k++) {
						min_sol[i+l][j+1][k+is_passes] = min(min_sol[i+l][j+1][k+is_passes], min_sol[i][j][k] + grid[i+l][j+1]);
					}
				}
			}
		}
	}
	int real_min = MAX_INT;
	for(int i = 0; i < r; i++) {
		real_min = min(real_min,min_sol[i].back().back());
	}
	if(real_min == MAX_INT) {
		cout << "impossible" << endl;
		return;
	}
	cout << real_min << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
