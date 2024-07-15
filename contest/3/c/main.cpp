#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int diff(string &a, string &b) {
  int counter = 0;
  for (int i = 0; i < a.size(); i++) {
    counter += abs(a[i] - b[i]);
  }
  return counter;
}

void solution() {
  int n_words, size;
  cin >> n_words >> size;
  vector<string> words(n_words);
  string mid_word;
  for (auto &i : words) {
    cin >> i;
  }
  string word1 = words[0], word2 = words[1];
  int lowest_diff = INT_MAX;
  for (int i = 0; i < n_words; i++) {
    for (int j = i + 1; j < n_words; j++) {
			int d = diff(words[i], words[j]);
			if(d < lowest_diff) {
				word1 = words[i];
				word2 = words[j];
				lowest_diff = d;
			}
    }
  }
	cout << lowest_diff << endl;
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
