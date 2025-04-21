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
    string s;
    cin >> s;
    string old_s;
    old_s = s;

    int l = MAX_INT;
    int r = MAX_INT;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }
    for (int i = l + 1; i < n; i++) {
        if (s[i] == '0') {
            r = i;
            break;
        }
    }
    for (int i = r + 1; i < n; i++) {
        if (s[i] == '0') {
            r = i;
        } else {
            break;
        }
    }
    if (l != MAX_INT && r != MAX_INT) {
        reverse(s.begin() + l, s.begin() + r+1);
    }
    int counter = 0;
    int actual  = '0';
    int other   = '1';
    for (int i = 0; i < n; i++) {
        if (s[i] == actual) {
            counter++;
        } else {
            counter += 2;
            swap(actual, other);
        }
    }

    cout << counter << endl;
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
