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
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool status = false;

    if ((x1 <= x2 && x1 + a >= x2) || (x2 <= x1 && x2 + a >= x1)) {
        int dist = 0;
        if (y1 > y2) {
            dist = y1 - (y2 + b);
        } else {
            dist = y2 - (y1 + b);
        }
        if (dist % b != 0) {
            cout << "No" << endl;
            return;
        }
    } else {
        int dist1 = 0;
        if (y1 > y2) {
            dist1 = y1 - (y2 + b);
        } else {
            dist1 = y2 - (y1 + b);
        }
        if (dist1 % b == 0) {
            status |= true;
        }
    }
    if ((y1 <= y2 && y1 + b >= y2) || (y2 <= y1 && y2 + b >= y1)) {
        int dist = 0;
        if (x1 > x2) {
            dist = x1 - (x2 + a);
        } else {
            dist = x2 - (x1 + a);
        }
        if (dist % a == 0) {
            cout << "No" << endl;
            return;
        }
    } else {
        int dist2 = 0;
        if (x1 > x2) {
            dist2 = x1 - (x2 + a);
        } else {
            dist2 = x2 - (x1 + a);
        }
        if (dist2 % a == 0) {
            status |= true;
        }
    }
    cout << (status ? "Yes" : "No") << endl;
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
