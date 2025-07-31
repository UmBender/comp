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

int merge(vector<int> &arr, int left, int mid, int right) {
	int i = left, j = mid, k = 0;
	int invCount = 0;
	int temp[(right - left + 1)];

	while ((i < mid) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			++k;
			++i;
		} else {
			temp[k] = arr[j];
			invCount += (mid - i);
			++k;
			++j;
		}
	}

	while (i < mid) {
		temp[k] = arr[i];
		++k;
		++i;
	}

	while (j <= right) {
		temp[k] = arr[j];
		++k;
		++j;
	}

	for (i = left, k = 0; i <= right; i++, k++) { arr[i] = temp[k]; }

	return invCount;
}
int mergeSort(vector<int> &arr, int left, int right) {
	int invCount = 0;

	if (right > left) {
		int mid = (right + left) / 2;
		invCount = mergeSort(arr, left, mid);
		invCount += mergeSort(arr, mid + 1, right);
		invCount += merge(arr, left, mid + 1, right);
	}
	return invCount;
}

int getInversions(vector<int> arr, int n) { return mergeSort(arr, 0, n - 1); }

void solution() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto &i : p) { cin >> i; }
	vector<vector<int>> dp(2, vector<int>(n));
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		dp[0][i] = p[i];
		dp[1][i] = 2 * n - p[i];
	}
	int last = getInversions(p, n);
	for (int i = n - 1; i >= 0; i--) {
		p[i] = dp[1][i];
		int first = getInversions(p, n);

		if (last < first) {
			p[i] = dp[0][i];
		} else {
			last = first;
		}
	}
	int inversions = getInversions(p, n);
	cout << inversions << endl;
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
