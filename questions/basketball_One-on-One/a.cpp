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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i += 2) {
        char opt = s[i];
        int  num = s[i + 1] - '0';
        if (opt == 'A') {
            a += num;

        } else if (opt == 'B') {
            b += num;
        }
        if (a >= 11 && b < 10) {
            cout << "A" << endl;
            return;
        }
        if (b >= 11 && a < 10) {
            cout << "B" << endl;
            return;
        }
        if (b >= 10 && a >= 10) {
            if (a - b > 1) {
                cout << "A" << endl;
                return;

            } else if (b - a > 1) {
                cout << "B" << endl;
                return;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
