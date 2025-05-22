// clang-format off
#include <atcoder/all>
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
using mint = atcoder::modint;
// clang-format on

mint binom(int n, int k) {
    int left, right;
    if (k > n - k) {
        left  = k;
        right = n - k;
    } else {
        left  = n - k;
        right = k;
    }
    mint acc = 1;

    for (int i = left + 1; i <= n; i++) {
        acc *= mint(i);
    }
    for (int i = 2; i <= right; i++) {
        acc /= mint(i);
    }
    return acc;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        mint acc = pref[i];
        for (int j = 1; j <= k; j++) {
            dp[i][j] = acc + dp[i - 1][j];
            acc *= pref[i];
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(dp[i].begin(), dp[i].end());
    }
    

    vector<mint> acc(n);
    for (int i = 0; i < n; i++) {
        mint actual = 1;
        for (int j = 0; j < k; j++) {
            // binom(n,k)
            if ((k - j) % 2 == 0) {

                acc[i] += binom(k, j) * dp[i][j] * actual;
            } else {
                acc[i] -= binom(k, j) * dp[i][j] * actual;
            }

            actual *= pref[i + 1];
        }
        acc[i] += actual * (i + 1);
    }
    mint sum = 0;
    for (auto &i : acc) {
        sum += i;
    }
    cout << sum.val() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
