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

int fast_exp(int base, int exp, int mod) {
	if(exp == 0) {
		return 1;
	}
	if(exp == 1) {
		return base;
	}
	int value = fast_exp(base, exp/2, mod);
	int result = value * value % mod;
	if(exp%2) {
		result *=base;
		result%= mod;
	}
	return result;
}

void solution() {
	int a,b,c;
	cin >> a >> b >> c;
	int mod = 1E9 + 7;
	int bc = fast_exp(b, c, mod - 1);
	int abc = fast_exp(a, bc, mod);
	cout << abc << endl;

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
