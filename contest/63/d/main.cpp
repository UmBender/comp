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

int cell_to_number(int actual_power, int x, int y, int acc) {
    if (actual_power <= 1) {
        return acc;
    }
    if (actual_power / 2 > x) {
        if (actual_power / 2 > y) {
            acc *= 4;
        } else {
            acc *= 4;
            acc += 2;
            y -= actual_power / 2;
        }
    } else {
        if (actual_power / 2 > y) {
            acc *= 4;
            acc += 3;
        } else {
            acc *= 4;
            acc += 1;
            y -= actual_power / 2;
        }
        x -= actual_power / 2;
    }
    actual_power /= 2;
    return cell_to_number(actual_power, x, y, acc);
}

pair<int, int> number_to_cell(int actual_power, int d) {
    if (actual_power == 1) {
        return {0, 0};
    }
    auto [x, y] = number_to_cell(actual_power / 2, d / 4);
    x *= 2;
    y *= 2;

    switch (d & 0b11) {
    case 1:
        x += 1;
        y += 1;
        break;
    case 2:
        y += 1;
        break;
    case 3:
        x += 1;
        break;
    default:
        break;
    }
    return {x, y};
}

void solution() {
    int n, q;
    cin >> n >> q;
    int actualpower = 1LL << n;

    while (q--) {
        string opt;
        cin >> opt;
        if (opt == "->") {
            int x, y;
            cin >> x >> y;
            cout << cell_to_number(actualpower, y - 1, x - 1, 0) + 1 << endl;
        }
        if (opt == "<-") {
            int d;
            cin >> d;
            auto [x, y] = number_to_cell(actualpower, d - 1);
            cout << y + 1 << " " << x + 1 << endl;
        }
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
