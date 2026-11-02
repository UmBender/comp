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
    string s;
    cin >> s;
    array<int, 27> cnt{};
    for (int i = 0; i < s.size(); i++) cnt[s[i] - 'A']++;
    for (int i = 0; i < 26; i++) {
        int v = cnt.at(i);
        if (v > (s.size() + 1) / 2) {
            cout << -1 << endl;
            return;
        }
    }
    string ans;
    ans.reserve(s.size());
    pair<int, int> last = {-1, 0};
    for (int i = 0; i < s.size(); i++) {
        int chosen = -1;

        for (int j = 0; j < 26; j++) {
            int remain = s.size() - i;
            if (cnt[j] > remain / 2) {
                chosen = j;
                break;
            }
        }

        if (chosen == -1) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] >= 1) {
                    chosen = j;
                    break;
                }
            }
        }

        if (last.first >= 0) { cnt[last.first] = last.second; }

        ans += 'A' + chosen;

        last.first = chosen;
        last.second = cnt[chosen] - 1;
        cnt[chosen] = 0;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
