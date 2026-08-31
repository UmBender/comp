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


constexpr int MAX_F = 1e6 + 100;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> f(n);
	for (int i = 0; i < n; i++) cin >> f[i];
	sort(begin(f), end(f));
	vector<int> counter(MAX_F);

	for (int i = 0; i < n; i++) {
		counter[f[i]]++;
	}
	
	int count = 0;
	for (int i = MAX_F - 1; i > 0; i--) {
		if (counter[i] == 0) {
			continue;
		}

		count += counter[i];



		int acc = 0;
		int temp = i;
		
		while (temp) {
			acc += temp % 10;
			temp /= 10;
		}
		if (count >= k) {
			cout << acc << endl;
			return 0;
		}

		counter[i - acc] += counter[i];
	}	
	cout << 0 << endl;
	return 0;
}

