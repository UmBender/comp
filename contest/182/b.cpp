#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vvi mat(n, vi(n));
    for (int i = 0; i < (n * (n - 1)) / 2; i++) {
        int u, v, gu, gv;
        cin >> u >> v >> gu >> gv;
        int first = 3, second = 0;
        if (gv > gu) swap(first, second);
        if (gv == gu) first = 1, second = 1;
        u--, v--;
        mat[u][v] = first;
        mat[v][u] = second;
    }
    using Node = array<int, 3>;
    vector<Node> placar(n);
    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        int acc = 0;
        for (int j = 0; j < n; j++) { acc += mat[i][j]; }
        placar[i] = {-acc, 0, i};
        groups[acc].push_back(i);
    }

    vvi nmat(n, vi(n));
    for (auto &[_, v] : groups) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                nmat[v[i]][v[j]] = mat[v[i]][v[j]];
                nmat[v[j]][v[i]] = mat[v[j]][v[i]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int acc = 0;
        for (int j = 0; j < n; j++) { acc += nmat[i][j]; }
        placar[i][1] = -acc;
    }

    sort(begin(placar), end(placar));

    for (int i = 0; i < n; i++) { cout << placar[i][2] + 1 << " \n"[i == n - 1]; }

    return 0;
}
