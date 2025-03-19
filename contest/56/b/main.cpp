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
    int n, k;
    cin >> n >> k;
    vector<int>            a(n);
    vector<pair<int, int>> orda(n);
    vector<bool>           marked(n, false);
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        orda[i] = {a[i], i};
    }
    sort(orda.rbegin(), orda.rend());
    int counter = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            fill(marked.begin(), marked.end(), false);
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            int actual_counter = a[i];
            int used           = 1;
            marked[i]          = true;
            if (i > 0) {
                pq.push({a[i - 1], i - 1});
                marked[i - 1] = true;
                used++;
            }
            if (i < n - 1) {
                pq.push({a[i + 1], i + 1});
                marked[i + 1] = true;
                used++;
            }
            while (used < n) {
                auto [l, m] = pq.top();
                pq.pop();
                if (m > 0 && !marked[m - 1]) {
                    pq.push({a[m - 1], m - 1});
                    used++;
                }
                if (m < n - 1 && !marked[m + 1]) {
                    pq.push({a[m + 1], m + 1});
                    used++;
                }
            }
            while (pq.size() > 1) {
                pq.pop();
            }
            actual_counter += pq.top().first;
            counter = max(actual_counter, counter);
        }

    } else {
        for (int i = 0; i < k + 1; i++) {
            counter += orda[i].first;
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
