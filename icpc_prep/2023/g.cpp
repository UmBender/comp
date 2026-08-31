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
using Pt = complex<ll>;
#define xx real()
#define yy imag()
ll dot(Pt a, Pt b) { return (conj(a) * b).xx; }
ll cross(Pt a, Pt b) { return (conj(a) * b).yy; }
Pt perp(Pt a) { return Pt(-a.yy, a.xx); }
const ld EPS = 1e-9;
int sgn(ld x) { return (x > EPS) - (x < -EPS); }

vi convHull(vector<Pt> &pt) {
	int n = sz(pt), m;
	vi h, ord(n);
	auto add = [&]() {
		vi st;
		for (int i : ord) {
			while ((m = sz( st)) > 1) {
				Pt a= pt[st[m - 1]], b = pt[st[m - 2]], c = pt[i];
				if (cross(b - a, c - a) <= 0) break;
				st.pop_back();
			}
			st.pb(i);
		}
		st.pop_back();
		h.insert(h.end(), all(st));
	};

	iota(all(ord), 0);
	auto top = [](auto a) { return pair(a.xx, a.yy); };
	sort(all(ord), [&](int i, int j) { return top(pt[i]) > top(pt[j]);});
	add(), reverse(all(ord)), add();
	return h;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<Pt> xy(n);
	for (int i = 0; i < n; i++) {
		int r, im;
		cin >> r >> im;
		xy[i] = Pt(r, im);
	}


	vector<int> result = convHull(xy);
	sort(begin(result), end(result));
	result.erase(unique(begin(result), end(result)), end(result));
	for (int i: result) {
		cout << i + 1 << " ";
	}
	cout << endl;


	return 0;
}

