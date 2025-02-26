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


int count_two(int n) {
	int counter = 0;
	while(n % 2 == 0 && n != 0) {
		n/=2;
		counter++;
	}
	return counter;
}
vector<int> factor_two(int n) {
	vector<int> elements(n);
	elements[0] = 0;
	for(int i = 1; i < n; i++) {
		elements[i] = elements[i - 1] + count_two(n-i) - count_two(i);
	}
	return elements;
}

void solution() {
	int n,k;
	cin >> n >> k;
	vector<int> caps = factor_two(n);
	for(int i = 0 ; i < n;i++) {
		cout << (!caps[i] ? k : 0)<< " ";
	}
	cout << endl;

	
  
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
