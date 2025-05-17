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
    int fodase;
    cout << "digit" << endl;
    cout.flush();
    cin >> fodase;
    cout << "digit" << endl;
    cout.flush();
    cin >> fodase;
    cout << "add -8" << endl;
    cout.flush();
    cin >> fodase;
    cout << "add -4" << endl;
    cout.flush();
    cin >> fodase;
    cout << "add -2" << endl;
    cout.flush();
    cin >> fodase;
    cout << "add -1" << endl;
    cout.flush();
    cin >> fodase;
    cout << format("mul {}", n) << endl;
    cout.flush();
    cin >> fodase;
    cout << "!" << endl;
    cout.flush();
    cin >> fodase;
}

int32_t main() {
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
