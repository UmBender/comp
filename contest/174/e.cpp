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

struct Point {
    ll x, y;
};

ll cross(Point &a, Point &b) { return a.x * b.y - a.y * b.x; }

ll half(Point &p) { return (p.y > 0 || (p.y == 0 && p.x > 0)) ? 0 : 1; }

void solve() {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (auto &point : p) { cin >> point.x >> point.y; }

    sort(p.begin(), p.end(), [](Point &a, Point &b) {
        if (half(a) != half(b)) { return half(a) < half(b); }
        return cross(a, b) > 0;
    });
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i + 1);

        while (j < i + n && cross(p[i], p[j % n]) > 0) { j++; }

        ans = max(ans, ll(j - i));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
