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
using ll = long long;
using ld = long double;
//using mint = atcoder::modint;
// clang-format on

vector<bool> is_prime(5E6 + 100, true);
vector<ll> primes;
vector<ll> values(5E6 + 100);
vector<ll> prefix_sum(5E6 + 101);
void sieve() {
	is_prime[0] = false;
	is_prime[1] = false;
	primes.push_back(2);
	values[0] = 0;
	values[1] = 0;
	values[2] = 1;

	for (ll j = 2; j < is_prime.size(); j += 1 + (j % 2)) {
		if (is_prime[j]) {
			primes.push_back(j);
			values[j] = 1;
			for (ll l = 2; l * j < is_prime.size(); l++) {
				is_prime[l * j] = false;
				values[l * j] = max(values[l * j], values[l] + 1);
			}
		}
	}
	for (ll j = 0; j < values.size(); j++) {
		prefix_sum[j + 1] = prefix_sum[j] + values[j];
	}
}

void solution() {
	ll a, b;
	cin >> a >> b;
	cout << prefix_sum[a + 1] - prefix_sum[b + 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	sieve();
	ll t;
	cin >> t;
	while (t--) solution();

	return 0;
}
