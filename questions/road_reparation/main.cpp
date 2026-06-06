#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

struct Dsu {
    int sets;
    int n;
    vector<int> parents;
    vector<int> sizes;
    Dsu(int n) : sets(n), n(n), parents(n), sizes(n, 1) {
        iota(parents.begin(), parents.end(), 0);
    }

    int get(int node) {
        if (node == parents[node]) {
            return node;
        }
        int parent = get(parents[node]);
        parents[node] = parent;
        return parent;
    }

    int same(int first, int second) {
        return get(first) == get(second);
    }

    bool join(int first, int second) {
        first = get(first);
        second = get(second);
        if (first == second) {
            return false;
        }
        if (sizes[first] < sizes[second]) {
            swap(first, second);
        }
        sizes[first] += sizes[second];
        parents[second] = first;
        sets--;
        return true;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    map<pair<int,int>, int> cs;
    set<pair<int,pair<int,int>>> bridges;
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cs[make_pair(a,b)] = c;
        cs[make_pair(b, a)] = c;
        bridges.insert(make_pair(c, make_pair(a, b)));
    }
    Dsu dsu(n);
    int acc = 0;
    while (!bridges.empty()) {
        auto cab = bridges.begin();
        bridges.erase(cab);
        auto [c, ab] = *cab;
        if (!dsu.same(ab.first, ab.second)) {
            acc += c;
            dsu.join(ab.first, ab.second);

        }
    }
    if (dsu.sets > 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << acc << endl;
    
    return 0;
}
