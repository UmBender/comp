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
void b_sieve();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	b_sieve();
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

bool sieve[(int)1e6 + 100];
const int SIEVE_LENGTH = 1e6;
vector<int> primes;
void b_sieve() {
	sieve[0] = true;
	sieve[1] = true;
	primes.push_back(2);
	for (int i = 4; i < SIEVE_LENGTH; i += 2) { sieve[i] = false; }
	for (int i = 3; i * i <= SIEVE_LENGTH; i += 2) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i * i; j < SIEVE_LENGTH; j += i) { sieve[j] = true; }
		}
	}
}

void solution() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	sort(a, a + n);
	int mmin = MAX_INT;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < primes.size(); j++) {
			if (a[i] % primes[j] == 0) {
				while (a[i] % primes[j] == 0) { a[i] /= primes[j]; }
			} else {
				mmin = min(primes[j], mmin);
				break;
			}
		}
	}
	cout << mmin << endl;
}
