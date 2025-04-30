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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int counter = 0;
    if ((n & 1) == 0) {
        for (int i = 0; i < n / 2 - 1; i++) {
            int a1 = a[i], a2 = a[n - i - 1];
            int b1 = a[i + 1], b2 = a[n - i - 2];
            if (a1 != a2) {
                if (b1 == b2) {
                    if (b1 == a1 || b1 == a2) {
                        counter++;
                    }
                }

            } else {
                if (b1 == b2) {
                    if (b1 == a1) {
                        counter += 2;
                    }
                } else {
                    if (b1 == a1 || b2 == a1) {
                        counter += 1;
                    }
                }
            }
        }
        if (a[n / 2 - 1] == a[n / 2]) {
            counter++;
        }

    } else {
        for (int i = 0; i < n / 2 - 1; i++) {
            int a1 = a[i], a2 = a[n - i - 1];
            int b1 = a[i + 1], b2 = a[n - i - 2];
            if (a1 != a2) {
                if (b1 == b2) {
                    if (b1 == a1 || b1 == a2) {
                        counter++;
                    }
                }

            } else {
                if (b1 == b2) {
                    if (b1 == a1) {
                        counter += 2;
                    }
                } else {
                    if (b1 == a1 || b2 == a1) {
                        counter += 1;
                    }
                }
            }
        }
        if (n >= 3) {
            int a1 = a[n / 2 - 1];
            int a2 = a[n / 2 + 1];
            int b  = a[n / 2];
            if (a1 == b) {
                counter++;
            }
            if (a2 == b) {
                counter++;
            }
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
