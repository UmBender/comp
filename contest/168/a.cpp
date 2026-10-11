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
    int diffs = 0;
    char last = s[0];
    for (int i = 0; i < s.size(); i++) {
        if (last != s[i]) { diffs++; }
        last = s[i];
    }
    if (diffs != 1) {
        cout << "NAO" << endl;
    } else {
        cout << "SIM" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
