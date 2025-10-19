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
vector<int> primes;
int8_t sieve[(int)2e5 + 100];
const int MAX_PRIME = 2e5 + 100;
void do_sieve() {
	for (int i = 0; i < MAX_PRIME; i++) { sieve[i] = 1; }
	sieve[0] = 0;
	sieve[1] = 0;
	for (int i = 4; i < MAX_PRIME; i += 2) { sieve[i] = 0; }
	for (int i = 3; i * i < MAX_PRIME; i += 2) {
		if (sieve[i]) {
			for (int j = i * i; j < MAX_PRIME; j += i) { sieve[j] = 0; }
		}
	}
	for (int i = 0; i < MAX_PRIME; i++) {
		if (sieve[i]) { primes.push_back(i); }
	}
}
void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	do_sieve();
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
	int a[n], b[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; }
	int ones = 0;
	sort(a, a + n);
	set<int> non_ones;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ones++;
		} else {
			if (!non_ones.count(a[i])) {
				non_ones.insert(a[i]);
			} else {
				cout << 0 << endl;
				return;
			}
		}
	}

	if (ones == n) {
		cout << 2 << endl;
		return;
	}
	map<int, int> factors;
	map<int, int> alt;

	for (int i = 0; i < n; i++) {
		int actual = a[i];
		int p = 0;
		while (actual > 1 && p < primes.size() &&
		       primes[p] * primes[p] <= actual) {
			if (actual % primes[p] == 0) {
				factors[primes[p]]++;
				while (actual % primes[p] == 0) { actual /= primes[p]; }
			}
			p++;
		}
		if (actual != 1) { factors[actual]++; }
		actual = a[i] + 1;
		p = 0;
		while (actual > 1 && p < primes.size() &&
		       primes[p] * primes[p] <= actual) {
			if (actual % primes[p] == 0) {
				alt[primes[p]]++;
				while (actual % primes[p] == 0) { actual /= primes[p]; }
			}
			p++;
		}
		if (actual != 1) { alt[actual]++; }
	}
	for (auto [key, value] : factors) {
		if (value > 1) {
			cout << 0 << endl;
			return;
		}
	}

	for (auto [key, value] : factors) {
		if (value && alt[key]) {
			cout << 1 << endl;
			return;
		}
	}

	cout << 2 << endl;
}
