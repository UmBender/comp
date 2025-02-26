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

vector<string> caps(int n) {
	if(n == 1) {
		return {"0", "1"};
	}
	vector<string> actual = caps(n-1);
	for(int i = actual.size() - 1; i >= 0; i--) {
		actual.push_back(actual[i]);
		actual[i]+= "0";
		actual.back() += "1";
	}
	return actual;
}

void solution() {
	int n;
	cin >> n;
	vector<string> actual = caps(n);
	for(auto i: actual) {
		reverse(i.begin(), i.end());
		cout << i << endl;
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
	solution();

  return 0;
}
