// clang-format off
#include <atcoder/modint.hpp>
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
using mint = atcoder::modint;
// clang-format on

mint fast_pow(mint base, int exp) {

    mint acc = 1;
    if (exp == 1) {
        return 2;
    }
    if (exp == 0) {
        return 1;
    }
    int  div    = exp / 2;
    mint actual = fast_pow(2, div);
    acc *= actual * actual;
    if (exp % 2) {
        acc *= 2;
    }
    return acc;
}

void solution() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    for (auto &i : p) {
        cin >> i;
    }
    for (auto &i : q) {
        cin >> i;
    }
    set<pair<int, int>> ps;
    set<pair<int, int>> qs;
    vector<mint>        results(n);
    for (int i = 0; i < n; i++) {
        ps.insert({p[i], i});
        qs.insert({q[i], i});
        auto maxx_pi = ps.end();
        maxx_pi--;
        auto [pmax, ppos] = *maxx_pi;
        auto maxx_qi      = qs.end();
        maxx_qi--;
        auto [qmax, qpos] = *maxx_qi;
        int first;
        int second;

        if (pmax > qmax) {
            first  = pmax;
            second = q[i - ppos];
        } else if (qmax > pmax) {
            first  = qmax;
            second = p[i - qpos];

        } else {
            int psecond = q[i - ppos];
            int qsecond = p[i - qpos];
            if (psecond > qsecond) {
                first  = pmax;
                second = psecond;

            } else {
                first  = qmax;
                second = qsecond;
            }
        }
        mint first_power  = fast_pow(2, first);
        mint second_power = fast_pow(2, second);
        results[i]        = first_power + second_power;
    }
    for (int i = 0; i < n; i++) {
        cout << results[i].val() << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
