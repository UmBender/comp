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
    int n;
    string s;
    cin >> n >> s;
    int actual = 0, longest = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            actual++;
        } else {
            actual = 0;
        }
        longest = max(longest, actual);
    }
    cout << longest << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
