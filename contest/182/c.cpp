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
    int n, m;
    cin >> n >> m;
    vi p(n);
    for (int &pi : p) {
        cin >> pi;
        pi--;
    }
    vvii adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    vi ans;
    auto invert = [&](int from, int to) -> vector<int> {
        vi acessed(n, 0);
        vii path(n);
        path[from] = {-1, 0};
        queue<int> qq;
        qq.push(from);
        while (!qq.empty()) {
            int actual = qq.front();
            qq.pop();
            if (from == to) { break; }
            for (auto [next, it] : adj[actual]) {
                if (acessed[next]) { continue; }
                acessed[next] = 1;
                path[next] = {actual, it};
                qq.push(next);
            }
        }
        vi ans;
        for (int pos = to; pos != from;) {
            ans.push_back(path[pos].second);
            pos = path[pos].first;
        }
        vi other = ans;
        ans.pop_back();
        reverse(begin(other), end(other));
        for (int oi : other) ans.push_back(oi);
        return ans;
    };
    for (int i = 0; i < n; i++) {
        if (p[i] == i) { continue; }
        int target = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] == i) { target = j; }
        }
        if (target == i) {
            cout << "Erro" << endl;
            return 1;
        }

        auto temp = invert(i, target);
        swap(p[i], p[target]);
        for (int ti : temp) { ans.push_back(ti); }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) { cout << ans[i] + 1 << " \n"[i == ans.size() - 1]; }

    return 0;
}
