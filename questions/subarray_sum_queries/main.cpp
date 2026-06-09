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

struct Node {
    ll left, right, full, mmax;
};

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

ostream &operator<<(ostream &os, Node &node) {
    os << format("Node(left: {}, right: {}, full: {}, max: {})", node.left,
                 node.right, node.full, node.mmax);
    return os;
}

Node op(Node left, Node right) {
    ll nleft = max({left.left, left.full + right.left});
    ll nright = max({
        right.right,
        right.full + left.right,
    });
    ll nfull = left.full + right.full;
    ll nmmax = max({left.mmax, right.mmax, nfull, nleft, nright,
                    left.right + right.left, 0ll});
    auto temp = Node(nleft, nright, nfull, nmmax);
    return temp;
}

Node e() { return Node(0, 0, 0, 0); }
using St = Segtree<Node, op, e>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (auto &xi : x) {
        cin >> xi;
    }
    St st(n);
    for (int i = 0; i < n; i++) {
        auto actual = Node(x[i], x[i], x[i], max(x[i], 0ll));
        st.set(i, actual);
    }
    while (m--) {
        ll k, x;
        cin >> k >> x;
        auto actual = Node(x, x, x, max(x, 0ll));
        k--;
        st.set(k, actual);
        cout << max(0ll, st.query(0, n).mmax) << endl;
    }

    return 0;
}
