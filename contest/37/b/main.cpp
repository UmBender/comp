#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

vector<int> count(string &word) {
  vector<int> counter(256,0);

  for(auto i: word) {
    counter[i]++;
  }

  return counter;
}

void solution() {
  string word;
  cin >> word;

  for(int i = 0; i < word.size() - 1;i++) {
    if(word[i] == word[i+1]) {
      cout << 1 << endl;
      return;
    }

  }

  cout << word.size() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
