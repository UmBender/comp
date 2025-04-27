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

void solution() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<bool, set<int>>> users(n);
    fill(users.begin(), users.end(), make_pair(false, set<int>()));
    for (int qq = 0; qq < q; qq++) {
        int opt;
        cin >> opt;
        switch (opt) {
        case 1: {
            int x, y;
            cin >> x >> y;
            if (!users[x - 1].second.count(y)) {
                users[x - 1].second.insert(y);
            }
        } break;
        case 2: {
            int x;
            cin >> x;
            users[x - 1].first = true;
        } break;
        case 3: {
            int x, y;
            cin >> x >> y;
            if (users[x - 1].first) {
                cout << "Yes" << endl;
                continue;
            }
            if (users[x - 1].second.count(y)) {
                cout << "Yes" << endl;
                continue;
            }
            cout << "No" << endl;

        } break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
