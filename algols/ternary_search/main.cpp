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

int find_max(function<int(int)> conc) {
	int left = -1E6 - 100;
	int right = 1E6 + 100;
	while(right - left > 3) {
		int ml = left + (right-left)/3;
		int mr = right - (right-left)/3;
		if(conc(ml) < conc(mr)) {
			left = ml;
		}else{
			right = mr;
		}
	}

	int max_pos = left;
	for(int i = left; i <= right; i++) {
		if(conc(max_pos) < conc(i)) {
			max_pos = i;
		}
	}
	return max_pos;
}

int find_min(function<int(int)> conc) {
	int left = -1E9 - 100;
	int right = 1E9 + 100;
	while(right - left > 3) {
		int ml = left + (right - left)/3;
		int mr = right - (right -left) / 3;
		if(conc(ml) > conc(mr)) {
			left = ml;
		}else{
			right = mr;
		}
	}
	int min_pos = left;
	for(int i = left; i <= right; i++) {
		if(conc(i) < conc(min_pos)) {
			min_pos = i;
		}
	}
	return min_pos;
}

void solution() {
	// x^2 -8x + 12
	function<int(int)> func_min = [](int x) {
		return x * x - 8LL * x + 12LL;
	};
	// -x^2 + 8x - 12
	function<int(int)> func_max = [](int x) {
		return -(x * x) + 8LL * x - 12LL;
	};
	cout << find_min(func_min) << endl;
	cout << find_max(func_max) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
