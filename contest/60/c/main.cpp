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
    vector<int> p(n);
    for(auto &i: p) {
        cin >> i;
    }

    vector<bool>marked(n);
    vector<int> d(n);
    for(auto &i: d) {
        cin >> i;
    }
    vector<int> solves;
    int counter = 0;
    for(int mod: d) {
        while(!marked[mod-1]) {
            marked[mod-1] = true;
            counter ++;
            mod =  p[mod-1];
        }
        solves.push_back(counter);
    }
    for(int i = 0; i < solves.size();i++) {
        cout << solves[i] << " \n"[i==solves.size()-1];
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
