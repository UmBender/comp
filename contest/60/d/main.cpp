// clang-format off
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using namespace atcoder;
using mint = modint998244353;
// clang-format on

vector<int> c(26);
mint        counter = 0;
int         length;

mint fact(int x) {
    mint base = 1;
    for (int i = 2; i < x; i++) {
        base *= i;
    }
    return base;
}
void dfs(int actual, vector<int> &left, int sleft, vector<int> &right,
         int sright) {
    if (sleft > (length + 1) / 2 || sright > length / 2) {
        return;
    }

    if (actual >= 26) {
        mint lleft = 1;
        for (int i : left) {
            lleft *= fact(i);
        }
        mint rright = 1;
        for (int i : right) {
            rright *= fact(i);
        }
        mint topl = fact(sleft);
        mint topr = fact(sright);
        topl /= lleft;
        topr /= rright;
        mint result = topl * topr;
        counter += result;
        return;
    }
    left.push_back(c[actual]);
    sleft += c[actual];
    dfs(actual + 1, left, sleft, right, sright);
    left.pop_back();
    sleft -= c[actual];
    right.push_back(c[actual]);
    sright += c[actual];
    dfs(actual + 1, left, sleft, right, sright);


}

void solution() {
    length  = 0;
    counter = 0;
    for (auto &i : c) {
        cin >> i;
        length += i;
    }
    vector<int> right, left;
    dfs(0,left, 0, right, 0);
    cout << counter.val() << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
