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
    vector<vector<int>> adj(n + 1), rev(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int b;
            cin >> b;
            adj[i].push_back(b);
            rev[b].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << rev[i].size() << " ";
        sort(all(rev[i]));
        for (int k = 0; k < rev[i].size(); k++) {
            cout << rev[i][k] << " \n"[k == rev[i].size() - 1];
        }
        if (rev[i].size() == 0) {
            cout << endl;
        }
    }

    return 0;
}
