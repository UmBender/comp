// #include <atcoder/all>
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
// using mint = atcoder::modint;

void build(int first, vector<int> &a1, vector<int> &a2) {
  vector<int> a(a1.size() * 2 + 1);
  a[0] = first;
  for (int i = 0; i < a1.size(); i++) {
    a[i * 2 + 1] = a1[i];
  }
  for (int i = 0; i < a1.size(); i++) {
    a[i * 2 + 2] = a2[i];
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " \n"[i == a.size() - 1];
  }
}

void solution() {
  int n;
  cin >> n;
  vector<int> b(n * 2);
  set<int> check;
  for (auto &i : b) {
    cin >> i;
    check.insert(i);
  }

  sort(b.rbegin(), b.rend());
  vector<int> a1(n), a2(n);
  int sum_a1 = 0, sum_a2 = 0;
  for (int i = 0; i < n; i++) {
    a1[i] = b[i];
    sum_a1 += a1[i];
  }
  for (int i = 0; i < n; i++) {
    a2[i] = b[i + n];
    sum_a2 += a2[i];
  }
  if (sum_a2 != sum_a1 && !check.count(sum_a1 - sum_a2)) {
    build(sum_a1 - sum_a2, a1, a2);
    return;
  }

  swap(a1.front(), a2.front());
  int maxx = a2.front();
  a2.front() = 0;
  sum_a1 = 0;
  sum_a2 = 0;
  for (int i = 0; i < n; i++) {
    sum_a1 += a1[i];
  }
  for (int i = 0; i < n; i++) {
    sum_a2 += a2[i];
  }
  a2.front() = maxx + sum_a1 - sum_a2;
  build(maxx, a2, a1);
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
