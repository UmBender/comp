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
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int gcdv = a[0];
    for (int i = 1; i < n; i++) {
        gcdv = __gcd(a[i], gcdv);
    }
    bool there_is_gcd = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == gcdv) {
            there_is_gcd = true;
            break;
        }
    }
    if (there_is_gcd) {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != gcdv) {
                counter++;
            }
        }
        cout << counter << endl;
        return;
    }

    set<int> actual_gcds;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int actual = __gcd(a[i], a[j]);
            if (!actual_gcds.count(actual) && actual != a[i]) {
                actual_gcds.insert(actual);
            }
        }
    }
    set<int> new_gcds;
    int      counter = 1;
    while (!actual_gcds.count(gcdv)) {
        for (auto i : actual_gcds) {
            for (int j = 0; j < n; j++) {
                int actual = __gcd(i, a[j]);
                if (!new_gcds.count(actual) && actual != a[j]) {
                    new_gcds.insert(actual);
                }
            }
        }
		counter++;
		swap(new_gcds,  actual_gcds);
		new_gcds.clear();
    }
	cout<<counter +a.size() - 1 <<endl;
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
