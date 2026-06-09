#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

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

ll op(ll first, ll second) { return min(first, second); }
ll e() { return 1e18; }

using Minseg = Segtree<ll, op, e>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    queue<ll> nums;
    auto st = Minseg(k);
    int pos = 0;
    ll ans = 0;
    nums.push(x);

    st.set(pos, x);
    pos++;
    pos %= k;
    ll last = x;
    while (pos) {
        int actual = (last * a + b) % c;
        last = actual;
        st.set(pos++, actual);
        pos %= k;
        n--;
    }
    while (n--) {
        ll mmin = st.query(0, k);
        ans ^= mmin;
        last = (last * a + b) % c;
        st.set(pos++, last);
        pos %= k;
    }
    cout << ans << endl;
    return 0;
}
