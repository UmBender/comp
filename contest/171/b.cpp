#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    map<string, int> ans;
    for (int i = 0; i < n; i++) { ans[s[i]] = 0; }
    for (int i = 0; i < m; i++) {
        if (ans.count(t[i])) {
            ans[t[i]]++;
            continue;
        }
        vector<string> rem;
        for (int j = 0; j < t[i].size(); j++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string temp = t[i];
                temp[j] = ch;
                if (ans.count(temp)) {
                    rem.push_back(temp);
                    ans[temp]++;
                }
            }
        }
        if (rem.size() > 1) {
            for (auto &i : rem) { ans[i]--; }
        }
    }
    for (int i = 0; i < n; i++) { cout << ans[s[i]] << endl; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
