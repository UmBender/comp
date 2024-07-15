#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    mp[q]++;
  }
  int b = -1, end = -1;
  int size = 0;
  int realb = -1, rend = -1;
  int rsize = 0;
  for (auto &[i, j] : mp) {
    if (j >= k) {
      if (b == -1) {
        b = i;
      } else {
        if (end == -1 && b == i - 1) {
          end = i;
          size++;
        } else if (end != -1 && end == i - 1) {
          end = i;
          size++;
        } else {
          if (rend - realb < end - b) {

            realb = b;
            rend = end;
          }
          b = i;
          end = -1;
        }
      }
    } else {
      if (rend - realb < end - b) {

        realb = b;
        rend = end;
      }
      b = -1;
      end = -1;
    }
  }
  cout << realb << " " << rend << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
