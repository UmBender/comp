#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void teste1(string &a, string &b) {
  int biggest = 0;
  for (int i = 0; i < a.size(); i++) {
    int counter = 0;
    for (int j = 0; j < b.size() && i + j < a.size(); j++) {
      counter += a[i + j] == b[j] ? 1 : 0;
    }
    if (counter > biggest) {
      biggest = counter;
    }
  }
  cout << (a.size() + b.size()) - biggest << endl;
}

void teste2(string &a, string &b) {
  int biggest = 0;
  for (int k = 0; k < b.size(); k++) {
    int counter = 0;
    int i = 0, j = 0;
    while (i < a.size() && k + j < b.size()) {
      if (a[i] == b[k +j]) {
        counter++;
        i++;
        j++;
      } else {
				i++;
      }
    }

    if (counter > biggest) {
      biggest = counter;
    }
  }
	cout << (a.size() + b.size()) - biggest << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  vector<string> a(t), b(t);
  for (int i = 0; i < t; i++) {
    cin >> a[i];
    cin >> b[i];
  }

  for (int i = 0; i < t; i++) {
    if (a.size() > b.size()) {
      teste1(a[i], b[i]);
    } else {
      teste2(a[i], b[i]);
    }
  }
  return 0;
}
