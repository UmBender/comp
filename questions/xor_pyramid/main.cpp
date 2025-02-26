#include <atcoder/all>
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
using mint = atcoder::modint;

int factors_two(int n) {
	int counter = 0;
	while(n!= 0 && n % 2 == 0) {
		n/=2;
		counter++;
	}
	return counter;
}

vector<int> factors(int n) {
	vector<int> elements(n);
	for(int i = 1; i <= n; i++) {
		elements[i] = elements[i-1] + factors_two(n - i) -factors_two(i);
	}
	return elements;

}

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i: a) {
		cin >> i;
	}
	int acc = 0;
	vector<int>fac = factors(n);
	for(int i = 0; i < n; i ++) {
		if(!fac[i]) {
			acc ^= a[i];
		}
	}
	cout << acc << endl;
  
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
