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
    string ss;
    cin >> ss;
    int         n = ss.size();
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = ss[i] - '0';
    }

    vector<int> counter_odd(10);
    for (int i = 0; i < n; i++) {
        counter_odd[s[i]]++;
    }
    int mmin = MAX_INT;
    for (int i = 0; i < 10; i++) {
        mmin = min(mmin, n - counter_odd[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int removes           = 0;
            int holder_removes[2] = {0, 0};

            int counter           = 0;
            for (int k = 0; k < n; k++) {
                if (counter % 2 == 0) {
                    if (s[k] == i) {
                        counter = 1 - counter;
                    } else {
                        holder_removes[counter]++;
                    }
                } else {
                    if (s[k] == j) {
                        counter = 1 - counter;
                        removes += holder_removes[0] + holder_removes[1];
                        holder_removes[0] = 0;
                        holder_removes[1] = 0;

                    } else {
                        holder_removes[counter]++;
                    }
                }
            }
            if (counter == 0) {
                removes += holder_removes[0] + holder_removes[1];
            } else {
                removes += holder_removes[0] + holder_removes[1] + 1;
            }
            mmin = min(mmin, removes);
        }
    }
    cout << mmin << endl;
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
