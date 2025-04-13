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
    int q;
    cin >> q;
    deque<int> elements;
    int        sum       = 0;
    int        front     = 0;
    int        back      = 0;
    int        size      = 0;
    bool       direction = true;
    for (int i = 0; i < q; i++) {
        int opt;
        cin >> opt;
        switch (opt) {
        case 1:
            if (direction) {
                front += sum;
                front -= elements.back() * size;
                back -= sum;
                back += elements.back() * size;
                int actual = elements.back();
                elements.pop_back();
                elements.push_front(actual);
                cout << front << endl;
            } else {
                front -= sum;
                front += elements.front() * size;
                back += sum;
                back -= elements.front() * size;
                int actual = elements.front();
                elements.pop_front();
                elements.push_back(actual);
                cout << back << endl;
            }
            break;
        case 2:
            direction = !direction;
            if (direction) {
                cout << front << endl;
            } else {
                cout << back << endl;
            }

            break;
        case 3:
            int k;
            cin >> k;
            if (direction) {
                front += k * (size + 1LL);
                sum += k;
                back += sum;
                elements.push_back(k);
                cout << front << endl;
            } else {
                back += k * (size + 1LL);
                sum += k;
                front += sum;
                elements.push_front(k);
                cout << back << endl;
            }
            size++;
            break;
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
