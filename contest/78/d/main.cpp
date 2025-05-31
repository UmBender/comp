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
#define makefn(fn) [](auto... args) { return fn(args...); }
//using mint = atcoder::modint;
// clang-format on

/*
 *    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ss(n);
    for (int i = 0; i < n; i++) {
        ss[i] = (s[i] == '1');
    }
    vector<int> counter[2];
    vector<int> rcounter[2];
    for (int i = 0; i < 2; i++) {
        counter[i]  = vector<int>(n);
        rcounter[i] = vector<int>(n);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 && i < n - 1; j++) {
            rcounter[j][i] = rcounter[j][i + 1];
        }
        rcounter[ss[i]][i]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 && i; j++) {
            counter[j][i] = counter[j][i - 1];
        }
        counter[ss[i]][i]++;
    }

        vector<int> modif(n);
        for(int i = 0; i < n; i++) {
                modif[i] =

        }

        */
void solution() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ss(n);
    for (int i = 0; i < n; i++) {
        ss[i] = (s[i] == '1');
    }
    int maxxone         = 0;
    int maxxone_init    = MAX_INT;
    int maxx_length     = MAX_INT;
    int possible_length = 0;
    int begin_now       = 0;
    int actualone       = 0;
    for (int i = 0; i < n; i++) {
        actualone += 2 * ss[i] - 1;
        possible_length++;
        if (actualone < 1) {
            actualone       = 0;
            possible_length = 0;
            begin_now       = i + 1;
        }
        if (actualone > maxxone) {
            maxxone      = actualone;
            maxxone_init = begin_now;
            maxx_length  = possible_length;
        }
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (i < maxxone_init || i >= maxxone_init + maxx_length) {
            counter += ss[i];
        } else {
            counter += !ss[i];
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
