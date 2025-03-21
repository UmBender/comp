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
    vector<bool> ss(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ss[i] = true;
        }
    }
    vector<bool> first, second;
    int          p = -1;
    first          = ss;
    for (int i = 0; i < first.size(); i++) {
        if (!first[i]) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << 1 << ' ' << s.size() << ' ' << 1 << ' ' << 1 << endl;
        return;
    }

    int l    = 0;
    int maxx = 0;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < first.size() - p && first[j+p] != first[i + j]; j++) {
            if (j + 1 > maxx) {
                maxx = j + 1;
                l    = i;
            }
        }
    }
    cout << 1 << ' ' << s.size() << ' ' << l + 1 << ' ' << l + first.size() -p << endl;
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
