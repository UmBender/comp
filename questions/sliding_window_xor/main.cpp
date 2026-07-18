#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using vl = vector<ll>;
using pll = pair<ll, ll>;
#define endl '\n'


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll k, n;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	queue<int> values;
	ll all = 0;
	ll acc = 0;

	values.push(x);
	acc ^= x;
	while (values.size() < k) {
		x = (a * x + b);
		x %= c;
		acc ^= x;
		values.push(x);
	}
	all ^= acc;
	for (int i = k; i < n; i++) {
		x = (a * x + b);
		x %= c;
		ll last = values.front();
		values.pop();
		values.push(x);
		acc ^= last;
		acc ^= x;
		all ^= acc;
	}
	cout << all << endl;

	return 0;
}
