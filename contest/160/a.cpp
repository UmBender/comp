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
constexpr int MAX_N = 2e5 + 100;
int n;
int a[MAX_N];
map<int,int>counter;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counter[a[i]]++;
	}
	auto [k, v] = *counter.rbegin();
	if (v > 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (k == a[i]) {
			cout << i + 1 << endl;
			break;
		}
	}
    return 0;
}
