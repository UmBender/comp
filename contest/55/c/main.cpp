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
    vector<int> first(1E6);
    vector<int> second(1E6);
    vector<int> a(n);
    int         maxx  = 0;
    int         left  = 0;
    int         right = 0;
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        if (first[a[i]] == 0) {
            left++;
        }
        first[a[i]]++;
    }
    maxx = max(left + right, maxx);
    for (int i = 0; i < n; i++) {
        first[a[i]]--;
        if (first[a[i]] == 0) {
            left--;
        }
        if (second[a[i]] == 0) {
            right++;
        }
        second[a[i]]++;
        maxx = max(left + right, maxx);
    }
    cout << maxx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
