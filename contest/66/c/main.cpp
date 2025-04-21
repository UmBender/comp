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

bool by_front(vector<int> a, int k) {
    int         n = a.size();
    vector<int> counter(n + 1);
    for (int i = 0; i < n; i++) {
        counter[i + 1] = counter[i] + (a[i] <= k ? 1 : -1);
    }
    int first_r = -1;
    for (int i = 1; i <= n; i++) {
        if (counter[i] >= 0) {
            first_r = i;
            break;
        }
    }
    if (first_r == -1) {
        return false;
    }
    while (counter[first_r + 1] >= 0 && first_r + 1 <= n &&
           counter[first_r + 1] < counter[first_r] && n - first_r > 2) {
        first_r++;
    }

    int second_r = -1;
    for (int i = first_r + 1; i < n; i++) {
        if (counter[i] - counter[first_r] >= 0) {
            second_r = i;
            break;
        }
    }
    if (second_r != -1) {
        return true;
    }
    int third_l = -1;
    for (int i = n - 1; i > first_r; i--) {
        if (counter[n] - counter[i] >= 0) {
            third_l = i;
            break;
        }
    }
    if (third_l != -1) {

        return true;
    }
    return false;
}
bool by_back(vector<int> a, int k) {
    reverse(a.begin(), a.end());
    int         n = a.size();
    vector<int> counter(n + 1);
    for (int i = 0; i < n; i++) {
        counter[i + 1] = counter[i] + (a[i] <= k ? 1 : -1);
    }
    int first_r = -1;
    for (int i = 1; i <= n; i++) {
        if (counter[i] >= 0) {
            first_r = i;
            break;
        }
    }
    if (first_r == -1) {
        return false;
    }
    while (counter[first_r + 1] >= 0 && first_r + 1 <= n &&
           counter[first_r + 1] < counter[first_r] && n - first_r > 2) {
        first_r++;
    }

    int second_r = -1;
    for (int i = first_r + 1; i < n; i++) {
        if (counter[i] - counter[first_r] >= 0) {
            second_r = i;
            break;
        }
    }
    if (second_r != -1) {
        return true;
    }
    int third_l = -1;
    for (int i = n - 1; i > first_r; i--) {
        if (counter[n] - counter[i] >= 0) {
            third_l = i;
            break;
        }
    }
    if (third_l != -1) {

        return true;
    }
    return false;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    if (by_front(a, k)) {
        cout << "YES" << endl;
        return;
    }
    if (by_back(a, k)) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
