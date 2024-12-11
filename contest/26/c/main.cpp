#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

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

int bigest_val(int val) {
  if (!val) {
    return 0;
  }
  int biggest = 0;
  while (val) {
    val /= 2;
    biggest *= 2;
    biggest += 1;
  }
  return biggest;
}

int biggest_digit(int n) {
  if (!n) {
    return 0;
  }
  int val = 1;
  while (n /= 2) {
    val *= 2;
  }
  return val;
}

bool validate(vector<int> &p, int n) {
  int k = 0;
  for (int i = 0; i < p.size(); i++) {
    if (i % 2) {
      k |= p[i];
    } else {
      k &= p[i];
    }
  }
  cerr << "N: " << n << endl;
  return k == n;
}

void solution() {
  int n;
  cin >> n;
  vector<int> p;
  int k;
  if (n % 2) {
    cout << n << endl;
    k = n;
    p.push_back(n);
    n--;
  } else {
    cout << bigest_val(n) << endl;
    k = bigest_val(n);
  }
  if (n == 4) {
    vector<int> caps = {2, 1, 3, 4, 5};
    for (auto i : caps) {
      cout << i << ' ';
    }
    cout << endl;
    return;
  }
  bool ended = false;
  while (!ended) {
    int biggest = bigest_val(n);
    p.push_back(n);
    if (biggest == n) {
      n -= 1;
      continue;
    }
    int caps = biggest ^ n;

    int upbit = 0;
    while (1) {
      if ((caps | (0x1 << upbit)) != caps) {
        upbit = caps | (0x1 << upbit);
        break;
      }
      upbit++;
    }
    if (upbit < caps) {
      ended = true;
      p.push_back(caps);
      p.push_back(upbit);
      p.push_back(2);
    } else {
      n = caps;
    }
  }
  reverse(p.begin(), p.end());
  for (auto i : p) {
    cout << i << ' ';
  }
  cout << endl;
  cerr << "VALIDADE: " << validate(p, k) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;

  while (t--) {
    solution();
  }

  return 0;
}
