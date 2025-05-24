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
    string s;
    cin >> s;
    int counter          = 0;
    int actual_increment = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int actual_number  = s[i] - '0';

        int number_of_rots = actual_increment % 10;
        while (number_of_rots) {
            actual_number--;
            if (actual_number < 0) {
                actual_number = 9;
            }
            number_of_rots--;
        }
        actual_increment += actual_number;
        counter += actual_number;
		counter++;
    }
	cout << counter << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
