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


#define MAX_INT ((int64_t)1E19)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll


inline int totwo(int x) {
	return x * x;
}

int big_sqrt(int k) {
	int l = 1;
	int r = 1E10;
	while(l <= r) {
		int m = l + ( r- l)/2;
		if(totwo(m)<= k && totwo(m+1) > k){
			return m;
		}
		if(totwo(m) > k) {
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return 0;
}

int sol(int target) {
	int l = 1;
	int r = MAX_INT;
	while(l <= r) {
		int n = l + (r - l) / 2;
		if(n - big_sqrt(n) >= target && (n-1) - big_sqrt(n-1) < target) {
			return n;
		}
		if(n - big_sqrt(n) < target) {
			l = n + 1;
		}else{
			r = n - 1;
		}

	}
	return -1;
}

void solution() {
	int k;
	cin >> k;
	cout << sol(k) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
	
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
