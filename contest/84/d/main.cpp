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
    vector<int> ab[2];
    for (int j = 0; j < 2; j++) {
        ab[j] = vector<int>(n);
    }
    for (int j = 0; j < 2; j++) {
        for (auto &i : ab[j]) {
            cin >> i;
        }
    }

    map<int, pair<int, int>> pos;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < n; k++) {
            pos[ab[j][k]] = {k, j};
        }
    }
    vector<string> op;
    for (int l = 1; l <= 2 * n; l++) {
        if (l % 2 == 1) {

            bool fix_side = pos[l].second == 0;
            while (pos[l].first != l / 2 || !fix_side) {
                if (!fix_side) {
                    op.push_back(format("3 {}", pos[l].first + 1));
                    swap(pos[l], pos[ab[!pos[l].second][pos[l].first]]);
                    swap(ab[0][pos[l].first], ab[1][pos[l].first]);
                    fix_side = true;
                } else {

                    op.push_back(format("1 {}", pos[l].first));
                    int actual_pos = pos[l].first;
                    int side       = pos[l].second;
                    swap(pos[l], pos[ab[side][actual_pos - 1]]);
                    swap(ab[side][actual_pos], ab[side][actual_pos - 1]);
                }
            }
        } else {
            bool fix_side = pos[l].second == 1;
            while (pos[l].first != l / 2 - 1 || !fix_side) {
                if (!fix_side) {
                    op.push_back(format("3 {}", pos[l].first));
                    swap(pos[l], pos[ab[!pos[l].second][pos[l].first]]);
                    swap(ab[0][pos[l].first], ab[1][pos[l].first]);
                    fix_side = true;
                    continue;
                } else {
                    op.push_back(format("2 {}", pos[l].first));

                    int actual_pos = pos[l].first;
                    int side       = pos[l].second;
                    swap(pos[l], pos[ab[side][actual_pos - 1]]);
                    swap(ab[side][actual_pos], ab[side][actual_pos - 1]);
                }
            }
        }
    }
    cout << op.size() << endl;
    for (auto i : op) {
        cout << i << endl;
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
