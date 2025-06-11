// clang-format off
//#include <atcoder/all>
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
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
// clang-format on

vector<int> fibs(10);

void _fill() {
    fibs[0] = 1;
    fibs[1] = 2;
    for (int i = 2; i < 10; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
}

vector<int> maxx(int n) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(fibs[i]);
    }
    return res;
}

void solution() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> boxes(m);
    for (auto &[w, l, h] : boxes) {
        cin >> w >> l >> h;
    }
    string      result;
    vector<int> fib = maxx(n);
    reverse(fib.begin(), fib.end());
    int biggest = fib[0];
    int second  = fib[1];
    for (int i = 0; i < m; i++) {
        auto [w, l, h] = boxes[i];
        vector<pair<int, int>> poss;
        poss.push_back({w, l});
        poss.push_back({w, h});
        poss.push_back({l, h});
        bool it_possible = false;
        if (biggest > w || biggest > l || biggest > h) {
            result.push_back('0');
            continue;
        }
        for (auto [l, c] : poss) {
            if (l - biggest >= second) {
                it_possible |= true;
            }
            if (c - biggest >= second) {
                it_possible |= true;
            }
        }
        if (it_possible) {
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }
    cout << result << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    _fill();
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
