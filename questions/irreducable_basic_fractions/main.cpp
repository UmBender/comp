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

void solve(ll n) {
    ll m = n;
    if (n % 2 == 0) {
        m = (m - m / 2);
        while (n % 2 == 0) { n /= 2; }
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            m = (m - m / i);
            while (n % i == 0) { n /= i; }
        }
    }
    if (n != 1) { m = (m - m / n); }
    cout << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 1;
    while (true) {
        cin >> n;
        if (!n) break;
        solve(n);
    }
}
