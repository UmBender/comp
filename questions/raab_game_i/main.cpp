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
    int n, a, b;
    cin >> n >> a >> b;
    if (a == n || b == n || a + b > n) {
        cout << "NO" << endl;
        return;
    }
    if ((a == 0 && b != 0) || (a != 0 && b == 0)) {
        cout << "NO" << endl;
        return;
    }
    int draws = n - (a + b);
    int actual = n - draws;

    vector<int> f(actual), s(actual);

    for (int i = 0; i < actual; i++) { f[i] = i + 1; }
    for (int i = 0; i < actual; i++) {
        int shift = actual - b;
        s[i] = (i + shift) % actual + 1;
    }
    while (f.size() < n) {
        s.push_back(f.size() + 1);
        f.push_back(f.size() + 1);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) { cout << f[i] << " \n"[i == n - 1]; }
    for (int i = 0; i < n; i++) { cout << s[i] << " \n"[i == n - 1]; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
