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
    
    vector<int> p(n + 1), d(n + 1), count(n + 1, 0), isDead(n + 1, 0);
    vector<vector<int>> childs(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> d[i]; 
        childs[p[i]].push_back(i);
    }
    
    auto dfs = [&](auto& self, int u) -> void {
        for (int v : childs[u]) {
            self(self, v);
            if (isDead[v]) {
                count[u]++;
            }
        }
        
        if (u == 0) {
			return;
		}
        
        if (d[u] > 0) {
            isDead[u] = 1;
        } 
        else if (count[u] > (int)childs[u].size() / 2) {
            isDead[u] = 1;
        }
    };
    
    dfs(dfs, 0);
    
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        counter += isDead[i];
    }
    
    cout << counter << "\n";

    return 0;
}
