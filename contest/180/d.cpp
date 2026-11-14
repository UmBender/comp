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
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;
    ll acc = 1;

    vector<int> freq;
    {
        vector<int> vals = a;
        sort(begin(vals), end(vals));
        vals.erase(unique(begin(vals), end(vals)), end(vals));
        for (int &ai : a) { ai = int(lower_bound(begin(vals), end(vals), ai) - begin(vals)); }
        freq = vector<int>(vals.size());
    }
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] != a[i - 1]) { acc += i - freq[a[i]]; }
        freq[a[i]]++;
    }
    cout << acc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
