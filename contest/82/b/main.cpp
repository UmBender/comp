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
    int n, q;
    cin >> n >> q;
    int x[q];

    for (int i = 0; i < q; i++) {
        cin >> x[i];
        x[i]--;
    }

    set<pair<int, int>> size_box;
    vector<int>         counter(n, 0);
    vector<int>         result;
    for (int i = 0; i < n; i++) {
        size_box.insert({0, i});
    }
    for (int i = 0; i < q; i++) {
        if (x[i] == -1) {
            auto first                      = size_box.begin();
            auto [actual_counter, position] = *first;
            counter[position]++;
            size_box.erase({actual_counter, position});
            size_box.insert({counter[position], position});
            result.push_back(position + 1);
        } else {
            size_box.erase({counter[x[i]], x[i]});
            counter[x[i]]++;
            size_box.insert({counter[x[i]], x[i]});
            result.push_back(x[i]+1);
        }
    }
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
