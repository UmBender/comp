#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define int ll
#define endl '\n'
#define pb(x) push_back((x))


bool checkPrime(ll p, ll a) {
	ll k = p - 1, d = 1;
	while (~k & 1) k >>= 1;
	for (ll e = k; e; e>>= 1) {
		if (e & 1) d = i128(d) * a % p;
		a = i128(a) * a % p;
	}
	if (d == 1 || d == p - 1) return true;
	while ((k <<= 1) < p - 1) {
		d = i128(d) * d % p;
		if (d == p - 1) return true;
	}
	return false;
}

bool isPrime(ll p) {
	if (p == 1) return false;
	for (int i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (p == i) return true;
		if (!checkPrime(p, i)) return false;
	}
	return true;
}

mt19937_64 rng64(random_device{}());
using ull = unsigned long long;
using u128 = __uint128_t;

ull modMul(ull a, ull b, ull mod) { return (u128)a * b % mod; }

ull G(ull a, ull b) { return b ? G(b, a % b) : a; }

ull rho(ull n) {
	if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
	ull c = uniform_int_distribution<ull>(1, n - 1)(rng64);
	ull x = uniform_int_distribution<ull>(0, n - 1)(rng64), y = x, d = 1;
	auto f = [&](ull x) { return (modMul(x, x, n) + c) % n; };
	while (d == 1) {
		x = f(x);
		y = f(f(y));
		d = G(x > y ? x - y : y - x, n);
	}
	return d == n ? rho(n) : d;
}

void factor(ull n, vector<ull> &fs) {
	if (n == 1) return;
	if (isPrime(n)) { fs.pb(n); return; }
	ull d = rho(n);
	factor(d, fs);
	factor(n / d, fs);
}



int32_t main() {
	int n;
	cin >> n;

	auto gs = [&](int a, int n) -> int{
		if (a == 0) return 0;
		if (a == 1) return 1;
		int currSum = 1;
		int currPow = 1;
		for (int i = 0; i < n; i++) {
			currPow *= a;
			currSum += currPow;
		}

		return currSum;
	};

	auto sum = [&](int x) -> int {
		if (x == 0 || x == 1) return 0;
		vector<ull> temp;
		factor(x, temp);
		sort(begin(temp), end(temp));
		int last = temp[0];
		int cnt = 0;
		int acc = 1;
		for (int i = 0; i < temp.size(); i++) {
			if (last == temp[i]) {
				cnt++;
				continue;
			}
			acc *= gs(last, cnt);
			last = temp[i];
			cnt = 1;
		}
		acc *= gs(last, cnt);
		acc -= x;
		return acc;
	};

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cout << sum(x) << endl;
	}
}
