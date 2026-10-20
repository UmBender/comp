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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> mins;
    vector<pair<int, int>> maxs;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        while (!maxs.empty() && maxs.back().first < a[i]) { maxs.pop_back(); }
        int lmin;
        if (maxs.empty()) {
            lmin = 0;
        } else {
            lmin = maxs.back().second + 1;
        }
        maxs.push_back({a[i], i});
        int l = 0, r = mins.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mins[m].second >= lmin) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (ans != -1) { cnt += mins.size() - (ans); }
        while (mins.size() && mins.back().first > a[i]) { mins.pop_back(); }
        mins.push_back({a[i], i});
    }
    maxs.clear();
    mins.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!maxs.empty() && maxs.back().first < a[i]) { maxs.pop_back(); }
        int lmin;
        if (maxs.empty()) {
            lmin = n - 1;
        } else {
            lmin = maxs.back().second - 1;
        }
        maxs.push_back({a[i], i});
        int l = 0, r = mins.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mins[m].second <= lmin) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (ans != -1) { cnt += mins.size() - (ans); }
        while (mins.size() && mins.back().first > a[i]) { mins.pop_back(); }
        mins.push_back({a[i], i});
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
