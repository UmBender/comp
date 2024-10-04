#pragma GCC optimize("O2")
#include <bits/stdc++.h>

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

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bs(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  if (arr.size() == 1) {
    if (arr[0] >= target) {
      return 0;
    }
    return -1;
  }
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (middle == 0) {
      if (arr[middle] >= target) {
        return middle;
      }
      if (arr[middle + 1] >= target) {
        return middle + 1;
      }
      return -1;
    }

    if (arr[middle] >= target && arr[middle - 1] < target) {
      return middle;
    }

    if (arr[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

void solution() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto &i : x) {
    cin >> i;
  }
  vector<int> holder;
  holder.push_back(x[0]);
  for (int i = 1; i < x.size(); i++) {
    int vbs = bs(holder, x[i]);
    if (vbs == -1) {
      holder.push_back(x[i]);
    } else {
      holder[vbs] = x[i];
    }
  }

  cout << holder.size() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
