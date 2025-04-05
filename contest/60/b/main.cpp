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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    int counter = 0;
    vector<int>pref(n+1);
    for(int i =0; i < n;i++)
        pref[i+1] = pref[i] + a[i];
    int last_end = 0;
    int last_val = 0;
    for (int i = 0; i < n; i++) {
        int j          = last_end;
        int actual_sum = last_val;
        if(i != 0) {
            actual_sum -= a[i-1];
        }
        for(; j < n&& actual_sum < x;j ++) {
            actual_sum+= a[j];
        }
        int rest = x - actual_sum;
        int iters = rest / pref.back();
        j += iters*n;
        actual_sum += iters*pref.back();
        while (actual_sum < x) {
            actual_sum += a[j % n];
            j++;
        }
        last_end = j;
        last_val = actual_sum;
        if(j > n * k) {
            break;
        }
        int poss = (n*k - j) / n;
        poss++;
        counter+= poss;


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
