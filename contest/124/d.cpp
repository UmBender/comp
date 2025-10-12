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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;
	vector<int> values(2 * n);
	set<int> actives;
	vector<bool> twice(2 * n);
	auto find_first = [&]() -> int {
		int i = 0;
		for (; i < 2 * n; i += 2) {
			cout << "? " << 2 << " " << i + 1 << " " << i + 2 << endl;
			cout.flush();
			int result;
			cin >> result;
			if (result == 0) {
				return i;
			} else {
				values[i] = result;
				values[i + 1] = result;
				twice[i] = true;
				twice[i + 1] = true;
			}
		}
		return i;
	};
	int bbegin = find_first();
	if (bbegin == 2 * n) {
		cout << "! ";
		for (int i = 0; i < 2 * n; i++) { cout << values[i] << " "; }
		cout << endl;
		cout.flush();
		return;
	}
	actives.insert(bbegin + 1);
	actives.insert(bbegin + 2);
	for (int i = bbegin + 2; i < 2 * n; i++) {
		if (twice[i]) { continue; }
		cout << "? " << actives.size() + 1 << " ";
		for (auto j : actives) { cout << j << " "; }
		cout << i + 1 << endl;
		cout.flush();
		int input;
		cin >> input;
		if (input == 0) {
			actives.insert(i + 1);
		} else {
			values[i] = input;
		}
	}
	set<int> known, not_known;
	for (int i = 0; i < 2 * n; i++) {
		if (values[i] == 0) {
			not_known.insert(i + 1);
		} else {
			if (!twice[i]) { known.insert(i + 1); }
		}
	}

	auto query_actual = [&](int val, set<int> &known) -> int {
		set<int> temp = known;
		temp.insert(val);

		cout << "? " << temp.size() << " ";
		for (auto i : temp) { cout << i << " "; }
		cout << endl;
		cout.flush();
		int input;
		cin >> input;
		return input;
	};

	for (auto actual_not : not_known) {
		int value = query_actual(actual_not, known);
		values[actual_not - 1] = value;
	}
	cout << "! ";
	for (int i = 0; i < 2 * n; i++) { cout << values[i] << " "; }
	cout << endl;
	cout.flush();
}
