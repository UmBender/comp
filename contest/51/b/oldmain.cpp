#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;
#define int ll

pair<string, string> freq[12] = {{"A", "A"},   {"A#", "Bb"}, {"B", "B"},
                                 {"C", "C"},   {"C#", "Db"}, {"D", "D"},
                                 {"D#", "Eb"}, {"E", "E"},   {"F", "F"},
                                 {"F#", "Gb"}, {"G", "G"},   {"G#", "Ab"}};
const long double base = 440;

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

  vector<vector<pair<long double, long double>>> solves;
  for (int j = -3; j < 5; j++) {
    vector<pair<long double, long double>> vers;
    for (int k = 0; k < 12; k++) {
      long double a = 12 * j;
      a += k;
      long double low = base * 0.9999 * pow(2.0, a / 12.0);
      long double high = base * 1.0001 * pow(2.0, a / 12.0);
      vers.push_back({low, high});
    }
    solves.push_back(vers);
  }

  int counter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < solves.size(); j++) {
      if (solves[j].front().first <= f[i] && f[i] <= solves[j].back().second) {
        for (int k = 0; k < solves[j].size(); k++) {
          if (solves[j][k].first <= f[i] && f[i] <= solves[j][k].second) {
            if (!pitchs.count(freq[k])) {
              pitchs.insert(freq[k]);
            }
            in_ord[i] = k;
            counter++;
            break;
          }
        }
        break;
      }
    }
  }
  if (counter != n) {
    cout << "cannot determine key" << endl;
    return;
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
