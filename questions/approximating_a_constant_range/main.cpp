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
    map<int, int> last_elements;
    int           mmax = 0;
    int           back = 0;
    for (int i = 0; i < n; i++) {
        if (last_elements.empty()) {
            last_elements[a[i]] = i;
        } else {
            int new_back = back;
            for (auto [k, j] : last_elements) {
                if (abs(k - a[i]) > 1) {
                    new_back = max(back, j + 1);
                }
            }
            vector<int> remove_elements;
            for (auto [k, j] : last_elements) {
                if (j < new_back) {
                    remove_elements.push_back(k);
                }
            }
            for (auto k : remove_elements) {
                last_elements.erase(k);
            }

            back                = new_back;
            last_elements[a[i]] = i;
        }

        mmax = max(mmax, i - back + 1);
    }
    cout << mmax << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
