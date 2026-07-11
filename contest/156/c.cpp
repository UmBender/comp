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


const int MAX_N = 3e5;
const int MAX_Q = 3e5;
int n, q, ni, qi;
pii hl[MAX_N], t[MAX_Q];
int ans[MAX_Q];
map<int,int> counter;


int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> hl[i].se >> hl[i].fi;
		counter[hl[i].se]++;
	}
	sort(hl, hl + n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t[i].fi;
		t[i].se = i;
	}
	sort(t, t + q);
	ni = 0, qi = 0;
	while (ni < n && qi < q) {
		if (hl[ni].fi <= t[qi].fi) {
			counter[hl[ni].se]--;
			if (counter[hl[ni].se] == 0) {
				counter.erase(hl[ni].se);
			}
			ni++;
			continue;
		}
		ans[t[qi].se] = counter.rbegin()->first;
		qi++;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}

    return 0;
}
