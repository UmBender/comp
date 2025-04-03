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
    sort(a.begin(), a.end());
    int mmax = a.back();
    a.pop_back();
    priority_queue<int> odd_queue, even_queue;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] & 1) {
            odd_queue.push(a[i]);
        } else {
            even_queue.push(a[i]);
        }
    }
    if (mmax % 2 == 0) {
        if (odd_queue.empty()) {
            cout << mmax << endl;
            return;
        }
        int actual = odd_queue.top();
        odd_queue.pop();
        mmax++;
        even_queue.push(actual - 1);
    }

    while (!even_queue.empty()) {
        int actual = even_queue.top();
        even_queue.pop();
        if (even_queue.empty()) {
            actual--;
            odd_queue.push(1);
        }
        mmax += actual;
    }
    while (mmax % 2 == 0 && !odd_queue.empty()) {
        int actual = odd_queue.top();
        odd_queue.pop();
        if (actual == 1) {
            mmax++;
            break;
        }
        mmax += actual - 1;
        odd_queue.push(1);
    }

    cout << mmax << endl;
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
