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

    int ar = 0, ac = 0, dr = 0, dc = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            char x;
            cin >> x;

            if (x == 'A') ar = r, ac = c;
            if (x == 'D') dr = r, dc = c;
        }
    }

    if (abs(ar - dr) + abs(ac - dc) == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
