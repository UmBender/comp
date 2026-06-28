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

struct Query {
    int r, c;
    char x;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<Query> qq(q);
    for (int i = 0; i < q; i++) {
        cin >> qq[i].r >> qq[i].c >> qq[i].x;
    }

    string grid(h * w, 'A');
    
    vector<int> maxC(h, 0);

    for (int i = q - 1; i >= 0; i--) {
        int r = qq[i].r - 1;
        int c = qq[i].c;
        char x = qq[i].x;

        for (int rr = r; rr >= 0; rr--) {
            if (maxC[rr] >= c) {
                break;
            }
            
            for (int cc = maxC[rr]; cc < c; cc++) {
                grid[rr * w + cc] = x;
            }
            maxC[rr] = c;
        }
    }

	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			cout << grid[r * w + c];
		}
		cout << endl;
	}
    return 0;
}
