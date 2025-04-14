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

int lbs(int minn, int maxx, vector<int> &values) {
    int l                = 0;
    int r                = values.size() - 1;
    int minimal_position = MAX_INT;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (values[m] >= minn && values[m] <= maxx) {
            minimal_position = values[m];
            r                = m - 1;
        }

        if (values[m] < minn) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (minimal_position == MAX_INT) {
        return -1;
    }
    return minimal_position;
}

vector<int> factors(int n, set<int> &fa) {
    vector<int> facts;
    for (auto i : fa) {
        if (i * i > n) {
            break;
        }
        if (n % i == 0) {
            fa.insert(i);
        }
    }
    return facts;
}

vector<vector<int>> val_pos(1E5 + 100);
void                solution() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<tuple<int, int, int>> queries(q);
    set<int>                     possiblek;
    for (auto &[k, l, r] : queries) {
        cin >> k >> l >> r;
        if (!possiblek.count(k)) {
            possiblek.insert(k);
        }
    }
    for (int i = 0; i < n; i++) {
        val_pos[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        auto [k, l, r] = queries[i];
        vector<pair<int, int>> pos_value;
        for (int j = 2; j * j <= k; j++) {
            if (k % j == 0) {

                int pos = lbs(l - 1, r - 1, val_pos[j]);
                if (pos != -1) {
                    pos_value.push_back({pos, j});
                }
                pos = lbs(l - 1, r - 1, val_pos[k / j]);
                if (pos != -1) {
                    pos_value.push_back({pos, k / j});
                }
            }
        }
        int pos = lbs(l - 1, r - 1, val_pos[k]);
        if (pos != -1) {
            pos_value.push_back({pos, k});
        }
        sort(pos_value.begin(), pos_value.end());
        int first      = l - 1;
        int actual_sum = 0;
        int actual_k   = k;
        for (int j = 0; j < pos_value.size(); j++) {
            if (actual_k % pos_value[j].second == 0) {
                int new_pos = pos_value[j].first;
                actual_sum += actual_k * (new_pos - first);
                swap(new_pos, first);
                while (actual_k % pos_value[j].second == 0) {
                    actual_k /= pos_value[j].second;
                }
            }
        }
        actual_sum += actual_k * (r - first);
        cout << actual_sum << endl;
    }
    for(auto &i: val_pos) {
        i.clear();
    }
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
