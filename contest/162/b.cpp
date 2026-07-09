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
	string s;
	cin >> s;
	stack<char> p;
	for (int i = 0; i < s.size(); i++) {
		if (p.empty()) {
			p.push(s.at(i));
			continue;
		}
		if (p.top() == s.at(i)) {
			p.pop();
		} else {
			p.push(s.at(i));
		}
	}
	cout << p.size() << endl;
    return 0;
}
