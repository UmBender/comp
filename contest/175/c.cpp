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
using i128 = __int128;

ll sqrtll(ll x) {
    ll l = 0, r = 1e7;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        ll actual = m * m;
        if (actual == x) { return m; }
        if (actual < x) {
            l = m + 1;
            continue;
        }
        r = m - 1;
    }
    return -1;
}

i128 gcd128(i128 a, i128 b) {
    while (b) {
        i128 r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n == 1) {
        ll sq = sqrtll(b[0]);
        cout << (sq != -1 && sq <= m) << endl;
        return;
    }

    ll num[2] = {1, 1};
    ll den[2] = {1, 1};

    ll required[2] = {1, 1};

    ll upper[2] = {min(m, b[0]), min(m, b[0])};

    ll maxB = *max_element(b.begin(), b.end());

    for (int i = 2; i < n; i++) {
        int p = i % 2;

        i128 a = (i128)num[p] * b[i - 1];
        i128 c = (i128)den[p] * b[i - 2];

        i128 g = gcd128(a, c);
        a /= g;
        c /= g;

        if (a > maxB || c > maxB) {
            cout << 0 << endl;
            return;
        }

        num[p] = (ll)a;
        den[p] = (ll)c;

        i128 need = (i128)(required[p] / gcd(required[p], den[p])) * den[p];

        if (need > b[0] || b[0] % (ll)need != 0) {
            cout << 0 << endl;
            return;
        }

        required[p] = ll(need);

        upper[p] = ll(min(i128(upper[p]), (i128)m * den[p] / num[p]));

        if (upper[p] < required[p]) {
            cout << 0 << endl;
            return;
        }
    }

    if (n % 2 == 0 && (i128)num[1] * b[0] != (i128)b[n - 1] * den[1]) {
        cout << 0 << endl;
        return;
    }

    vector<ll> divs;

    for (ll div = 1; div <= b[0] / div; div++) {
        if (b[0] % div != 0) continue;
        divs.push_back(div);
        if (div != b[0] / div) { divs.push_back(b[0] / div); }
    }

    ll cnt = 0;

    for (ll div : divs) {
        ll x0 = div;
        ll x1 = b[0] / div;

        if (x0 > upper[0] || x1 > upper[1]) continue;

        if (x0 % required[0] != 0) continue;
        if (x1 % required[1] != 0) continue;

        if (n % 2 != 0 && (i128)num[0] * x0 * x0 != (i128)b[n - 1] * den[0]) { continue; }

        cnt++;
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
