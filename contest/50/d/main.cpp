#include <atcoder/all>
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
using mint = atcoder::modint;

void solution() {
  int n, q;
  cin >> n >> q;

  vector<int> pigeon_to_field(n + 1);
  iota(pigeon_to_field.begin(), pigeon_to_field.end(), 0LL);
  vector<int> field_to_nest(n + 1);
  iota(field_to_nest.begin(), field_to_nest.end(), 0LL);
  map<int, int> nest_to_field;
  for (int i = 0; i <= n; i++) {
    nest_to_field[i] = i;
  }

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int a, b;
      cin >> a >> b;
      int true_field = nest_to_field[b];
      pigeon_to_field[a] = true_field;
    } else if (opt == 2) {
      int a, b;
      cin >> a >> b;
      int true_field_a = nest_to_field[a];
      int true_field_b = nest_to_field[b];
      swap(field_to_nest[true_field_a], field_to_nest[true_field_b]);
      swap(nest_to_field[a], nest_to_field[b]);
    } else {
      int a;
      cin >> a;
      int true_nest = field_to_nest[pigeon_to_field[a]];
      cout << true_nest << endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
