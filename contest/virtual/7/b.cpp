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

vector<int> zFunction(vector<int> s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}

	vector<int> temp;
	for (int j = 0; j < m; j++) {
		temp.push_back(b[j]);
	}


	temp.push_back(-1);
	for (int i = 0; i < n; i++) {
		temp.push_back(a[i]);
	}	
	auto result = zFunction(temp);
	int begin = m + 1;
	for (int i = begin; i < result.size(); i++) {
		if (result[i] == m) {
			cout << i - begin + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;

    return 0;
}
