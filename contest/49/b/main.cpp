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

int dsqrt(int x) {
  int i = 1;
  int j = 1E6 + 10;
  while (i <= j) {
    int m = i + (j - i) / 2;
    if (m * m == x) {
      return m;
    }
    if (m * m < x) {
      i = m + 1;
    }
    if (m * m > x) {
      j = m - 1;
    }
  }
  return -1;
}

int sap(int end) {
  int first = (end + 1);
  int second = end;
  if (first & 1) {
    second /= 2;
  } else {
    first /= 2;
  }
  return first * second;
}


void solution() {
  int n;
  cin >> n;
  int sum = sap(n);
  if (dsqrt(sum) != -1) {
    cout << -1 << endl;
    return;
  }
  vector<int> p(n);
  queue<int> q;
  
  for(int i = 1; i <=n;i++) {
    q.push(i);
  }
  int j =0;
  int acc = 0;

  while (!q.empty()) {
    int fron = q.front();
    q.pop();
    if(dsqrt(fron + acc) != -1) {
      q.push(fron);
    }else{
      acc += fron;
      p[j] = fron;
      j++;
    }
  }
  for(auto i: p) {
    cout << i << " ";
  }
  cout << endl;

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;

  while (t--)
    solution();


  return 0;
}
