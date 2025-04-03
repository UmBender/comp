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
    int first;
    cin >> first;
    queue<int> f;
    for (int i = 0; i < first; i++) {
        int x;
        cin >> x;
        f.push(x);
    }
    int second;
    cin >> second;
    queue<int> s;
    for (int i = 0; i < second; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    int                               count = 0;
    set<pair<queue<int>, queue<int>>> states;
    while (states.count({f, s}) == 0 && states.count({s, f}) == 0 && !s.empty() && !f.empty()) {
        states.insert({f, s});
        if (f.front() > s.front()) {
            int ff = f.front();
            int ss = s.front();
            s.pop();
            f.pop();
            f.push(ss);
            f.push(ff);

        } else {
            int ff = f.front();
            int ss = s.front();
            s.pop();
            f.pop();
            s.push(ff);
            s.push(ss);
        }
        count++;

    }
    if (states.count({f, s}) == 0 && states.count({s, f}) == 0) {
        int winner = f.empty() ? 2 : 1;
        cout << count << " " << winner << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
