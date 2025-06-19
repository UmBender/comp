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

const int SIZE = 1E6 + 10;
const int MOD  = 1E9 + 7;
int       solutions[2][SIZE];

void set_up() {
    solutions[0][0] = 0;
    solutions[1][0] = 0;
    solutions[0][1] = 1;
    solutions[1][1] = 1;
    for (ll j = 2; j < SIZE; j++) {
        solutions[0][j] = (solutions[0][j - 1] + solutions[1][j - 1] +
                           3 * solutions[0][j - 1]) %
                          MOD;
        solutions[1][j] =
            (solutions[0][j - 1] + solutions[1][j - 1] + solutions[1][j - 1]) %
            MOD;
    }
}

void solution() {
    int n;
    cin >> n;
    cout << ((solutions[0][n] + solutions[1][n]) % MOD) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    set_up();
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
