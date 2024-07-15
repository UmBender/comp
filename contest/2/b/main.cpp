#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
void teste(string &word) {
  int first_diff = -1;
  char word_diff = ' ';
  char first_letter = word[0];
  for (int i = 1; i < word.size(); i++) {
    if (first_letter != word[i]) {
			int holder = word[i];
			word[i] = word[0];
			word[0] = holder;
      cout << "YES" << endl;

      cout << word << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  vector<string> word(t);
  for (auto &i : word) {
    cin >> i;
  }
  for (auto &i : word) {
    teste(i);
  }

  return 0;
}
