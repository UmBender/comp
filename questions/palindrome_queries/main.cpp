#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

const int P = 676767677;
const int MOD = 998244353;

int add(int first, int second) {
    int temp = first + second;
    return (temp % MOD);
}

int zero() { return 0; }
int inv(int a) { return a <= 1 ? a : MOD - (long long)(MOD / a) * inv(MOD % a) % MOD; }


template <class S, S (*op)(S, S), S (*e)()> struct Segtree {
    vector<S> t;
    int n;
    Segtree(int N) : t(2 * N, e()), n(N) {}
    void set(int i, S value) {
        t[i += n] = value;
        for (i >>= 1; i; i >>= 1)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    } // 630e57
    S query(int l, int r) {
        S al = e(), ar = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                al = op(al, t[l++]);
            if (r & 1)
                ar = op(t[--r], ar);
        }
        return op(al, ar);
    } // 9ee903
};

int fastPow(int a, int b) {
    if (b == 0)
        return 1;
    long long res = fastPow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

vector<int> pPows(1e6 + 10000);
vector<int> invPows(1e6 + 10000);
void setup() {
    int pPow = 1;
    for (int i = 0; i < pPows.size(); i++) {
        pPows[i] = pPow;
        pPow *= P;
        pPow %= MOD;
    }
    invPows[0] = 1;
    invPows[1] = inv(P);
    for (int i = 2; i < invPows.size(); i++) {
        invPows[i] = invPows[i - 1] * invPows[1];
        invPows[i] %= MOD;
    }
}

using Seghash = Segtree<int, add, zero>;
int pHash(int pos, int val) {
    int actual = pPows[pos] * val;
    return actual % MOD;
}

signed main() {
    setup();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    Seghash normSeg(n), invSeg(n);

    auto update = [&](int pos, int val) {
        int calc = pPows[pos] * val;
        calc %= MOD;
        normSeg.set(pos, calc);
        int invP = n - 1 - pos;
        calc = pPows[invP] * val;
        calc %= MOD;
        invSeg.set(invP, calc);
    };
    for (int i = 0; i < n; i++) {
        update(i, s[i]);
    }

    auto query = [&](int l, int r) -> bool {
        int first = normSeg.query(l, r + 1);
        first *= invPows[l];
        first %= MOD;
        int invL = n - 1 - r;
        int invR = n - 1 - l;
        int second = invSeg.query(invL, invR + 1);

        second *= invPows[invL];
        second %= MOD;
        return first == second;
    };

    for (int mm = 0; mm < m; mm++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int k;
            char x;
            cin >> k >> x;
            update(k - 1, (int)x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << (query(l - 1, r - 1) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
