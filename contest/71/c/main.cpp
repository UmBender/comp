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
    map<int, set<int>> value_to_pos;
    for (int i = 0; i < n; i++) {
        value_to_pos[a[i]].insert(i);
    }
    set<int> pos_clones;
    int      clone_counter = 0;
    for (auto pos = value_to_pos.rbegin(); pos != value_to_pos.rend(); pos++) {
        auto &[i, j] = *pos;
        while (!j.empty()) {
            bool got_it = false;
            int  val    = 0;

            for (int k : j) {
                if (pos_clones.count(k - 1)) {
                    pos_clones.insert(k);
                    got_it = true;
                    val    = k;

                } else if (pos_clones.count(k + 1)) {
                    pos_clones.insert(k);
                    got_it = true;
                    val    = k;
                }
            }
            if (got_it) {
                j.erase(val);
            } else {
                auto val = *j.begin();
                j.erase(val);
                pos_clones.insert(val);
                clone_counter++;
                set<int> closed = {val};
                for (auto pp : value_to_pos[i]) {
                    for (auto l : closed) {
                        if (pp == l - 1) {
                            pos_clones.insert(l - 1);
                            closed.insert(l - 1);
                        }
                        if (pp == l + 1) {
                            pos_clones.insert(l + 1);
                            closed.insert(l + 1);
                        }
                    }
                }
            }
        }
    }
    cout << clone_counter << endl;
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
