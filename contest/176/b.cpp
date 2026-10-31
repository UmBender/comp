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
    string s[5];
    for (int i = 0; i < 5; i++) cin >> s[i];
    int mmin = 5;
    for (int i = 0; i < 5; i++) {
        int acc = 5;
        for (int j = 0; j < 5; j++) {
            if (s[i][j] == 'o') { acc--; }
        }
        mmin = min(acc, mmin);
    }
    for (int i = 0; i < 5; i++) {
        int acc = 5;
        for (int j = 0; j < 5; j++) {
            if (s[j][i] == 'o') { acc--; }
        }
        mmin = min(acc, mmin);
    }

    int acc = 5;
    for (int i = 0; i < 5; i++) {
        if (s[i][i] == 'o') { acc--; }
    }
    mmin = min(acc, mmin);

    acc = 5;
    for (int i = 0; i < 5; i++) {
        if (s[i][4 - i] == 'o') { acc--; }
    }

    mmin = min(acc, mmin);
    cout << mmin << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
