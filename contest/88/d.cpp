// clang-format off
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
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

vector<vector<int>> mat;
vector<int> edges;
vector<int> new_edges;
int mmin = MAX_INT;

void dfs(int op, int line, int column) {
	if (line == mat.size()) {
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i] != 2) { return; }
		}
		mmin = min(op, mmin);
		return;
	}
	int next_line, next_column;
	if (column + 1 >= line) {
		next_line = line + 1;
		next_column = 0;
	} else {
		next_line = line;
		next_column = column + 1;
	}
	if(mat[line][column] == 1) {

	}

	
}

void solution() {
	int n, m;
	cin >> n >> m;
	mat = vector<vector<int>>(n, vector<int>(n));
	edges = vector<int>(n);
	new_edges = vector<int>(n);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
