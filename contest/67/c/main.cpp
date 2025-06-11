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

bool calc(vector<pair<int, int>> ba, int k) {
    sort(ba.rbegin(), ba.rend());
    int target = ba[0].first + ba[0].second;
    int n      = ba.size();

    for (int i = 0; i < n; i++) {
        if (ba[i].first == -1) {
            ba[i].first = target - ba[i].second;
            if (ba[i].first > k || ba[i].first < 0) {
                return false;
            }
        } else {
            if (ba[i].first > k) {
                return false;
            }
            if (ba[i].first + ba[i].second != target) {
                return false;
            }
        }
    }
    return true;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ba(n);
    for (auto &i : ba) {
        cin >> i.second;
    }
    for (auto &i : ba) {
        cin >> i.first;
    }

    bool all_none = true;
    for (int i = 0; i < n; i++) {
        if (ba[i].first != -1) {
            all_none = false;
            break;
        }
    }
    if (!all_none) {
        if (calc(ba, k)) {
            cout << 1 << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }

    int min_value = MAX_INT;
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        max_value = max(max_value, ba[i].second);
        min_value = min(min_value, ba[i].second);
    }

    int max_target = min_value + k;
    if (max_target < max_value) {
        cout << 0 << endl;
        return;
    }
    cout << max_target - max_value + 1 << endl;
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
