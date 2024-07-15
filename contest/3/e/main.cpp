#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int bs(vector<int> &as, int target) {
  int begin = 0;
  int end = as.size()-1;
  while (begin <= end) {

    int middle = begin + (end - begin) / 2;
    if (as[middle] >= target && as[middle-1] < target) {
      return middle;
    }
    if (as[middle] < target) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
	if(as.front() > target) {
		return 1;
	}
  return -1;
}

void solution() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.rbegin(), a.rend());
  vector<int> prefx(n+1);
  prefx[0] = 0;
  for (int i = 0; i < n; i++) {
    prefx[i+1] = a[i] + prefx[i];
  }
  for (int i = 0; i < q; i++) {
		int qi;
		cin >> qi;
		cout << bs(prefx, qi) << endl;
  }
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
