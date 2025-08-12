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

const int INIT_VALUE = 0;
const int UNDEFINED = -1;
const int MAX_VALUE = 100LL * 100LL + 10LL;
pair<bool, vector<int>> is_possible(vector<int> &arr) {
	int sum = reduce(arr.begin(), arr.end(), 0LL);
	if (sum & 1LL) { return {false, {}}; }
	int target = sum / 2;
	vector<int> dp(MAX_VALUE, -1);
	for (auto i : arr) {

		for (int j = MAX_VALUE - 1; j >= 1; j--) {
			if (dp[j] != UNDEFINED) {
				if (i + j <= MAX_VALUE && dp[i + j] == UNDEFINED) {
					dp[i + j] = j;
				}
			}
		}
		if (dp[i] == UNDEFINED) { dp[i] = INIT_VALUE; }
	}
	if (dp[target] == UNDEFINED) { return {false, {}}; }
	vector<int> build;
	int actual = target;
	while (dp[actual] != 0) { build.push_back(actual - dp[actual]); actual = dp[actual];}
	build.push_back(actual);

	return {true, build};
}
void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	auto [is_poss, first] = is_possible(a);
	if (!is_poss) {
		cout << -1 << endl;
		return;
	} else {
		sort(a.rbegin(), a.rend());
		sort(first.rbegin(), first.rend());
		vector<int> second;
		int actual_first = 0;
		for (int i = 0; i < n; i++) {
			if (actual_first < first.size() && a[i] == first[actual_first]) {
				actual_first++;
			} else {
				second.push_back(a[i]);
			}
		}

		vector<int> result;
		int sum_first = 0;
		int sum_second = 0;
		int pos_first = 0;
		int pos_second = 0;
		while (pos_first < first.size() && pos_second < second.size()) {
			if (sum_first <= sum_second) {
				result.push_back(first[pos_first]);
				sum_first += first[pos_first];
				pos_first++;
			} else {
				result.push_back(second[pos_second]);
				sum_second += second[pos_second];
				pos_second++;
			}
		}
		while (pos_first < first.size()) {
			result.push_back(first[pos_first]);
			sum_first += first[pos_first];
			pos_first++;
		}
		while (pos_second < second.size()) {
			result.push_back(second[pos_second]);
			sum_second += second[pos_second];
			pos_second++;
		}

		int ssize = result.size();
		for (int i = 0; i < ssize; i++) {
			cout << result[i] << " \n"[i == ssize - 1];
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
