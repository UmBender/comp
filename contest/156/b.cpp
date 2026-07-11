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

const int MAX_N = 100;
vector<string> s(MAX_N);

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
    char x;
    cin >> x;
    x -= 'A';
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	bool counter[5];
	for ( int i = 0; i < 5; i++) {
		counter[i] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i][j] == 'o') {
				counter[j] = true;
			}
		}
	}


    cout << (counter[x] ? "Yes": "No") << endl;



    return 0;
}
