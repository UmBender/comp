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
    vector<pair<int, int>> monsters(n);
    for (auto &[i, j] : monsters) {
        cin >> i >> j;
    }
	if(n == 1){
		cout << 1 << endl;
		return;
	}
    set<pair<int, int>> monsters_xy, monsters_yx;
    for (int i = 0; i < n; i++) {
        monsters_xy.insert(monsters[i]);
        monsters_yx.insert({monsters[i].second, monsters[i].first});
    }
    int mmin = MAX_INT;
    for (int i = 0; i < n; i++) {
        pair<int, int> holder  = monsters[i];
        pair<int, int> swapped = {holder.second, holder.first};
        monsters_xy.erase(holder);
        monsters_yx.erase(swapped);
        int  upper_x, lower_x, upper_y, lower_y;

        auto iter = prev(monsters_xy.end());
        upper_x = (*iter).first;
        iter    = monsters_xy.begin();
        lower_x = (*iter).first;
        iter    = prev(monsters_yx.end());
        upper_y     = (*iter).first;
        iter        = monsters_yx.begin();
        lower_y     = (*iter).first;
        int delta_x = upper_x - lower_x + 1;
        int delta_y = upper_y - lower_y + 1;
        if (delta_x * delta_y >= n) {
            mmin = min(delta_x * delta_y, mmin);
        } else {
		
            mmin = min(delta_x * delta_y + min(delta_y, delta_x), mmin);
        }
		monsters_xy.insert(holder);
		monsters_yx.insert(swapped);
    }
    cout << mmin << endl;
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
