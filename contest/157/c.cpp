#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using iii = tuple<int, int, int>;
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), d(n), b(n);
	vector<iii> dab;
	map<int,int> count;
	vector<int> days(m + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> d[i] >> b[i];
		dab.emplace_back(d[i], a[i], b[i]);
		count[a[i]]++;
	}
	sort(begin(dab), end(dab)); 
	int j = 0;
	for (int i = 1; i <= m; i++) {
		while (j < n) {
			auto [td, ta, tb] = dab[j];
			if (td > i) {
				break;
			}
			count[ta]--;
			if (count[ta] <= 0){ 
				count.erase(ta);
			}
			count[tb]++;
			j++;
		}

		days[i] = sz(count);
	}
	for (int i = 1; i<=m;i++) {
		cout << days[i] << ' ';
	}
	cout << endl;

    return 0;
}
