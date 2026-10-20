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
struct PrefixHash {
    ll MOD;
    ll BASE;

    vector<ll> pref, invPow;

    ll modPow(ll a, ll e) {
        ll result = 1;
        while (e) {
            if (e & 1) result = result * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return result;
    }

    PrefixHash(string &s, ll mod, ll base)
        : pref(s.size() + 1), invPow(s.size() + 1, 1), MOD(mod), BASE(base) {

        ll invBase = modPow(BASE, MOD - 2);
        ll power = 1;

        for (int i = 0; i < (int)s.size(); ++i) {
            ll value = static_cast<unsigned char>(s[i]) + 1;

            pref[i + 1] = (pref[i] + value * power) % MOD;
            power = power * BASE % MOD;

            invPow[i + 1] = invPow[i] * invBase % MOD;
        }
    }

    ll get(int l, int r) {
        ll hash = (pref[r] - pref[l] + MOD) % MOD;
        return hash * invPow[l] % MOD;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 26>> pref(n + 1);
    vector<long long> h(n + 1, 0);
    PrefixHash prefHash1(s, 1e9 + 7, 676767677), prefHash2(s, 1e9 + 9, 676767677);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        pref[i + 1][s[i] - 'a']++;
    }
    auto getHash = [&](int l, int r) -> ll {
        return (prefHash1.get(l, r + 1) << 32) | prefHash2.get(l, r + 1);
    };
    auto first2 = [&](int begin) -> int {
        int l = begin, r = n - 1;
        int ans = -1;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            array<int, 26> diff = pref[m + 1];
            for (int i = 0; i < 26; i++) { diff[i] -= pref[begin][i]; }
            ll nTwo = 0;
            ll okay = true;
            for (int i = 0; i < 26; i++) {
                if (diff[i] > 2) {
                    okay = false;
                    break;
                }
                if (diff[i] == 2) { nTwo++; }
            }
            if (!okay || nTwo > 1) {
                r = m - 1;
                continue;
            }
            if (nTwo == 0) {
                l = m + 1;
                continue;
            }
            ans = m;
            r = m - 1;
        }
        return ans;
    };
    auto lastOkay = [&](int begin, int fOkay) -> int {
        int ans = fOkay;
        int l = fOkay, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            array<int, 26> diff = pref[m + 1];
            for (int i = 0; i < 26; i++) { diff[i] -= pref[begin][i]; }
            ll nTwo = 0;
            ll okay = true;
            for (int i = 0; i < 26; i++) {
                if (diff[i] > 2) {
                    okay = false;
                    break;
                }
                if (diff[i] == 2) { nTwo++; }
            }
            if (nTwo == 1 && okay) {
                ans = m;
                l = m + 1;
                continue;
            }
            r = m - 1;
        }
        return ans;
    };
    vector<set<ll>> hashes(28);
    auto checkFirstOut = [&](ll begin, ll firstOkay, ll lastOkay) -> ll {
        ll l = firstOkay, r = lastOkay;
        ll ans = -1;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            ll hash = getHash(begin, m);
            ll len = m - begin + 1;
            if (hashes[len].count(hash)) {
                l = m + 1;
                continue;
            }
            r = m - 1;
            ans = m;
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        int fOkay = first2(i);
        if (fOkay == -1) { continue; }
        int lOkay = lastOkay(i, fOkay);
        int fOut = checkFirstOut(i, fOkay, lOkay);
        if (fOut == -1) { continue; }
        for (int j = fOut; j <= lOkay; j++) {
            ll len = j - i + 1;
            hashes[len].insert(getHash(i, j));
        }
    }
    ll acc = 0;
    for (auto &s : hashes) acc += s.size();
    cout << acc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
