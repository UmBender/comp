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

int bs(int target, vector<int> &arr) {
    int left  = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (middle == 0) {
            if (arr[middle] >= target) {
                return middle;
            }
        } else {
            if (arr[middle - 1] < target && arr[middle] >= target) {
                return middle;
            }
        }
        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    map<int, int> right_most;
    set<int>      left_most;
    vector<int>   left;
    for (int i = 0; i < n; i++) {
        if (!right_most.count(a[i])) {
            right_most[a[i]] = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!left_most.count(a[i])) {
            left_most.insert(a[i]);
            left.push_back(i);
        }
    }
    reverse(left.begin(), left.end());

    int counter = 0;
    for (auto [i, j] : right_most) {
        int pos = bs(j, left);
        if (pos == -1) {
            continue;
        }
        counter += left.size() - pos;
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
