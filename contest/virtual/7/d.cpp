#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

#define int long long
constexpr int MAX_N = 1e6 + 100;
int notPrime[MAX_N];
int minDivisor[MAX_N];
int maxDivisor[MAX_N];

void setup() {
	notPrime[0] = 1;
	notPrime[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		minDivisor[i] = i;
		maxDivisor[i] = 1;
	}
	maxDivisor[2] = 2;
	for (int i = 4; i < MAX_N; i+=2) {
		notPrime[i] = 1;
		maxDivisor[i] = 2;
		minDivisor[i] = 2;
	}
	for (int i = 3; i < MAX_N; i+=2) {
		if (!notPrime[i]) {
			maxDivisor[i] = i;
			for (int j = 2 * i; j < MAX_N; j += i) {
				notPrime[j] = 1;
				maxDivisor[j] = max(maxDivisor[j], i);
				minDivisor[j] = min(minDivisor[j], i);
			}
		} 	
	}	
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	setup();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> bigs(n), tinys(n);
	for (int i = 0; i < n; i++) {
		int small = 0;
		int last = 1;
		int temp = a[i];
		
		while (temp > 1) {
			int div = minDivisor[temp];
			small += last;
			last *= div;
			temp /= div;
		}
		int big = 0;
		temp = a[i];
		last = 1;
		while(temp > 1) {
			int div = maxDivisor[temp];
			big += last;
			last *= div;
			temp /= div;
		}
		bigs[i] = big;
		tinys[i] = small;
	}
	int biggest = accumulate(all(bigs), 0ll);
	int smallest = accumulate(all(tinys), 0ll);
	cout << smallest << " " << biggest << endl;

    return 0;
}
