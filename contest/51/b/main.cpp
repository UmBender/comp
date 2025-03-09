#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define endl '\n'
using ll = long long;
#define int ll

pair<string, string> freq[12] = {{"A", "A"},   {"A#", "Bb"}, {"B", "B"},
                                 {"C", "C"},   {"C#", "Db"}, {"D", "D"},
                                 {"D#", "Eb"}, {"E", "E"},   {"F", "F"},
                                 {"F#", "Gb"}, {"G", "G"},   {"G#", "Ab"}};
const long double base = log(440);
const long double logb2 = log(2);

void solution() {
  int n;
  cin >> n;
  vector<long double> f(n);
  for (auto &i : f) {
    cin >> i;
  }
  set<pair<string, string>> pitchs;
  vector<int> in_ord(n);
  vector<pair<string, set<string>>> keys(5);
  keys[0] = {"G major", {"G", "A", "B", "C", "D", "E", "F#"}};
  keys[1] = {"C major", {"C", "D", "E", "F", "G", "A", "B"}};
  keys[2] = {"Eb major", {"Eb", "F", "G", "Ab", "Bb", "C", "D"}};
  keys[3] = {"F# minor", {"F#", "G#", "A", "B", "C#", "D", "E"}};
  keys[4] = {"G minor", {"G", "A", "Bb", "C", "D", "Eb", "F"}};

  vector<long double> pit(12);
  
  for (int i = 0; i < n; i++) {
    while(f[i] > 880.0E0) {
      f[i]/=2.0;
    }
    while(f[i] <= 440.0) {
      f[i] *=2.0;
    }

    long double actual = log(f[i]) - base;
    actual /= logb2;
    actual *= 12;
    int trunc = round(actual);
    trunc %=12;
    in_ord[i] = trunc;
    pitchs.insert(freq[trunc]);
  }

  vector<int> possi;
  for (int i = 0; i < keys.size(); i++) {
    bool equal = true;
    for (auto j : pitchs) {
      if (!keys[i].second.count(j.first) && !keys[i].second.count(j.second)) {
        equal = false;
      }
    }
    if (equal) {
      possi.push_back(i);
    }
  }

  if (possi.size() == 1) {
    cout << keys[possi.front()].first << endl;
    for (int j = 0; j < in_ord.size(); j++) {
      if (keys[possi.front()].second.count(freq[in_ord[j]].first)) {
        cout << freq[in_ord[j]].first << endl;
      }else{
        cout << freq[in_ord[j]].second << endl;
      }
    }
    return;
  }

  cout << "cannot determine key" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
