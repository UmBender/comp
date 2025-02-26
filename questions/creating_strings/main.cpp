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

map<char, int> letters;
vector<string> sols;

void create(string &acc, int counter) {

	for(auto [i,j]: letters) {
		if(j ==0) {
			continue;
		}
		letters[i]--;
		acc.push_back(i);
		counter --;
		if(counter == 0) {
			sols.push_back(acc);
		}else{
			create(acc,counter);
		}
		counter++;
		letters[i]++;
		acc.pop_back();
	}
}


void solution() {
	string s;
	cin >> s;
	int counter = 0;
	for(auto i: s) {
		letters[i]++;
		counter ++;
	}
	string k = "";
	create(k, counter);
	cout << sols.size() << endl;
	for(auto i: sols) {
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
