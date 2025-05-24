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
    int first_even = -1, last_even = -1;
    int first_odd = -1, last_odd = -1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            first_even = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            first_odd = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 0) {
            last_even = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 1) {
            last_odd = i;
            break;
        }
    }
    int even = MAX_INT;
    if (first_even != -1 && last_even != -1) {

        even = first_even + (n - 1 - last_even);
    }
	int odd = MAX_INT;
    if (first_odd != -1 && last_odd != -1) {

         odd = first_odd + (n - 1 - last_odd);
    }
	cout << min(odd,even) << endl;
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
