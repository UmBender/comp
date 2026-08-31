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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int d, c, r;
	cin >> d >> c >> r;
	vector<int> cs(c), rs(r);
	for (int &csi: cs) cin >> csi;
	for (int &rsi: rs) cin >> rsi;

	int first = 0, second = 0;
	int counter = 0;
	while (first < c && second < r) {
		if (cs[first] <= d) {
			counter++;
			d -= cs[first];
			first++;
		} else {
			counter++;
			d += rs[second];
			second++;
		}
	}
	while (first < c) {
		if (cs[first] > d) {
			break;
		}

		counter++;
		d -= cs[first];
		first++;
	}

	while (second < r) {
		counter++;
		d += rs[second];
		second++;
	}

	cout << counter << endl;


	return 0;
}

