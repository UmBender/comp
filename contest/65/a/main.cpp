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
    string s;
    cin >> s;
    int maxx = n;
    int minn = 1;
    vector<int> rest(n);

    for(int i = n-1; i > 0;i--) {
        if(s[i-1] == '>') {
            rest[i] = maxx;
            maxx--;
        }
        if(s[i-1] == '<'){
            rest[i] = minn;
            minn++;
        }
    }
    rest[0]= maxx;
    for(int i =0 ; i < n; i++) {
        cout << rest[i] <<  " \n"[i==n-1];
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
