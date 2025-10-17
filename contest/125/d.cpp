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
	int real_sum = ((1 + n) * n) / 2;
	cout << "2 1 " << n << endl;
	cout.flush();
	int a_sum;
	cin >> a_sum;
	int length = a_sum - real_sum;
	auto a_query = [](int left, int right) -> int {
		cout << "2 " << left + 1 << " " << right + 1 << endl;
		cout.flush();
		int result;
		cin >> result;
		return result;
	};
	auto x_query = [](int left, int right) -> int {
		cout << "1 " << left + 1 << " " << right + 1 << endl;
		cout.flush();
		int result;
		cin >> result;
		return result;
	};
	int left_equal = -1;
	int left = 0, right = n;
	while (left <= right) {
		int middle = (left + right) / 2;
		int base_result = x_query(0, middle);
		int mod_result = a_query(0, middle);
		if (base_result == mod_result) {
			left_equal = middle;
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	int left_result = left_equal + 2;

	int right_result = left_result + length - 1;
	cout << "! " << left_result << " " << right_result << endl;
	cout.flush();
	assert(right_result - left_result + 1 == length);
}
