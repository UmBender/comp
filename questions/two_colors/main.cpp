// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
//
int bs(int target, vector<int> &arr) {
    int left  = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (middle == 0) {
            if (arr[middle] >= target) {
                return middle;
            }
        } else if (arr[middle] >= target && arr[middle - 1] < target) {

            return middle;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    int counter = 0;
    for (int i = 1; i < n; i++) {
        int first_pos  = bs(i, a);
        int second_pos = bs(n - i, a);
        if (first_pos != -1 && second_pos != -1) {
            counter += (m-first_pos) * (m-second_pos);
            counter -= min(m-first_pos , m-second_pos);
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
