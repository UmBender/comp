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

/*
 *     set<vector<bool>> elements;
    for (int i = 0; i < n; i++) {
        if (!elements.count(ab[i])) {
            elements.insert(ab[i]);
        }
    }
    set<vector<bool>> old = elements, actual;
    vector<bool>      value_must;
    for (int i = 30; i >= 0; i--) {
        if (counter[i] == 0 || counter[i] == n) {
            continue;
        }
        if (counter[i] <= n / 2) {
            for (auto &ele : old) {
                if (ele[i]) {
                    actual.insert(ele);
                }
            }
        } else {
            for (auto &ele : old) {
                if (!ele[i]) {
                    actual.insert(ele);
                }
            }
        }
        if (actual.size() == 1) {
            value_must = *actual.begin();
            break;
        }
        if (actual.empty()) {
            value_must = *old.begin();
            break;
        }
        swap(old, actual);
        actual.clear();
    }
    if (value_must.empty()) {
        value_must = *old.begin();
    }
    int value = 0;
    for (int i = 30; i >= 0; i--) {
        value *= 2;
        value |= value_must[i] ? 1 : 0;
    }
    dbg(value);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (value ^ a[i]);
    }
    cout << sum << endl;

*/

void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.rbegin(), a.rend());
    vector<vector<bool>> ab(n, vector<bool>(31));
    for (int i = 0; i < n; i++) {
        int actual = a[i];
        for (int j = 0; j < 31; j++) {
            ab[i][j] = actual & 1;
            actual /= 2;
        }
    }
    vector<int> counter(31);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            counter[j] += ab[i][j];
        }
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int actual = 0;
        for (int j = 0; j < 31; j++) {
            if (ab[i][j]) {
                actual += (n - counter[j]) * (1LL << j);
            } else {
                actual += counter[j] * (1LL << j);
            }
        }
        maxx = max(maxx, actual);
    }
    cout << maxx << endl;
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
