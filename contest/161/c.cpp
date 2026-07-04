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
	int n;
	cin >> n;
	string s;
	cin >> s;
	deque<int> d;
	bool rev = false;
	for (int i = 1; i <= n; i++) {
		if (!rev) {
			d.push_back(i);
		} else {
			d.push_front(i);
		}
		if (s[i - 1] == 'o') {
			rev = !rev;
		}
	}
	if (rev) {
		reverse(d.begin(), d.end());
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] << " \n"[i == n - 1];
	}

    return 0;
}
