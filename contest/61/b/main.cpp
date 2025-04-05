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

void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.rbegin(), a.rend());
    int lower = a.back();
    a.pop_back();

    vector<int> sol;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] % lower == 0) {
            sol.push_back(a[i]);
        }
    }
    if (sol.size() == 0) {
        cout << "No" << endl;
        return;
    }
    int sol_bb = sol.back();
    sol.pop_back();
    while (!sol.empty()) {
        sol_bb = gcd(sol_bb, sol.back());
        sol.pop_back();
    }
    if (sol_bb == lower) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
