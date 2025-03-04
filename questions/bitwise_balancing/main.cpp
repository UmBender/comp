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

void solution() {
	int b, c, d;
	cin >> b >> c >> d;

	if((d &(2LL << 61)) && (b &(2LL << 61))) {
		cout << -1 << endl;
		return;
	}
	vector<int> tb(64), tc(64), td(64);
	int nb = b, nc = c, nd = d;
	for(int i = 0; i < tb.size(); i++) {
		tb[i] = nb & 1;
		nb >>=1;
	}
	for(int i = 0; i < tc.size(); i++) {
		tc[i] = nc & 1;
		nc >>=1;
	}
	for(int i = 0; i < td.size(); i++) {
		td[i] = nd & 1;
		nd >>= 1;
	}
	vector<int> ta;
	for(int i = 0; i < td.size(); i++) {
		for(int j = 0; j < 2; j++) {
			if((j | tb[i]) - (j & tc[i]) == td[i]) {
				ta.push_back(j);
				break;
			}
		}
	}
	int value = 0;
	if(ta.size() != 64) {
		cout << -1 << endl;
		return;
	}
	for(int i = ta.size() - 1; i >= 0; i--) {
		value*=2;
		value+= ta[i];
	}
	cout << value << endl;


  
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
