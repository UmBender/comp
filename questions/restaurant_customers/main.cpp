#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)

void solution() {
  int64_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> a(n);
  for(auto &i: a) {
    cin >> i.first >> i.second;
  }
  vector<int64_t> begin(n);
  vector<int64_t> end(n);
  for(int i = 0; i < n; i++) {
    begin[i] = a[i].first;
    end[i] = a[i].second;
  }


  sort(begin.begin(), begin.end());
  sort(end.begin(), end.end());
  int64_t i{0}, j{0};
  int64_t actual{0}, maxx{0};
  while(i < n || j < n) {
    if(i == n || j == n) {
      if(i == n) {
        actual--;
        j++;
      }else{
        actual++;
        i++;
      }
    }else{
      if(end[j] < begin[i]) {
        actual--;
        j++;
      }
      if(begin[i] <= end[j]){
        actual++;
        i++;
      }
    }
    maxx = max(maxx, actual);
  }
  cout << maxx << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
