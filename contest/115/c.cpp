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
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto check_sort = [&](char letter) -> bool {
		bool okay = true;
		for (auto i : s) {
			if (i != letter) {
				okay = false;
				break;
			}
		}
		return okay;
	};
	if (check_sort('1')) {
		cout << "YES" << endl;
		vector<int> p(n);
		iota(p.begin(), p.end(), 1LL);
		for (int i = 0; i < n; i++) { cout << p[i] << ' '; }
		cout << endl;
		return;
	}
	if (check_sort('0')) {
		cout << "YES" << endl;
		vector<int> p(n);
		iota(p.rbegin(), p.rend(), 1LL);
		for (int i = 0; i < n; i++) { cout << p[i] << ' '; }
		cout << endl;
		return;
	}
	vector<vector<int>> zeros;
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			first = i;
			break;
		}
	}
	vector<int> actual = {first};
	for (int i = first + 1; i < n; i++) {
		if (s[i] == '0') {
			actual.push_back(i);
		} else {
			if (s[i] == '1') {
				if (actual.empty()) {
					continue;
				} else {
					zeros.push_back(actual);
					actual.clear();
				}
			}
		}
	}
	if(!actual.empty()){
		zeros.push_back(actual);
	}
	for(int i =0 ; i< zeros.size(); i++) {
		if(zeros[i].size() == 1){
			cout << "NO" << endl;
			return;
		}
	}
	vector<int> p(n);
	for(int i = 0 ; i < n; i++) {
		if(s[i]=='1'){
			p[i] = i + 1;
		}
	}
	for(int i = 0; i < zeros.size();i++) {
		int left = zeros[i].front();
		int right = zeros[i].back();
		for(int j = left; j<= right; j++){
			p[j] = right - (j - left) + 1;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n;i++) {
		cout << p[i] << " ";
	}
	cout << endl;

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
