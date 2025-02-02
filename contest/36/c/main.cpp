#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

int bs(int target, vector<int> &arr) {
  int left = 1;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[0] - arr[middle] == target) {
      return middle;
    }

    if (arr[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

void solution() {
  int n;
  cin >> n;
  vector<vector<int>> queues(n);
  for (int i = 0; i < n; i++) {
    vector<int> a(n);
    for (int &j : a) {
      cin >> j;
    }
    queues[i] = a;
  }

  vector<int> ones(n);
  for(int i = 0; i < n; i++) {
    int one = 0;
    for(int j = n-1; j>=0;j--) {
      if(queues[i][j] == 1) {
        one++;
      }else{
        break;
      }
    }
    ones[i] = one;
  }
  sort(ones.begin(),ones.end());
  int counter  = 0;
  int actual = 0;
  for(int i = 0; i < n;i++) {
    if(ones[i]>= actual) {
      counter ++;
      actual+=1;
    }

  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solution();
  }

  return 0;
}
