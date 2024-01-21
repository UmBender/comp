#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int only_one(int val) {
  while ((val / 10) > 0) {
    int dasum = val % 10;
    val -= dasum;
    while (val / 10 > 0) {
      val /= 10;
      dasum += val % 10;
    }
    val = dasum;
  }

  return val;
}
char check_digit(string number) {
  int sum = 0;
  reverse(number.begin(), number.end());
  for (int i = 0; i < number.size(); i += 2) {
    int valrut = only_one(2 * ((int)number[i] - 48));
    sum += valrut;
  }
  for (int i = 1; i < number.size(); i += 2) {

    sum += (int)(number[i] - 48);
  }
  sum = 10 - (sum % 10);
  return sum == 10 ? '0' : sum + 48;
}

int32_t main() {
  vector<vector<string>> elements;
  for (int i = 0; i < 5; i++) {
    vector<string> new_elements;
    for (int j = 0; j < 5; j++) {
      string s;
      cin >> s;
      new_elements.push_back(s);
    }
    elements.push_back(new_elements);
  }
  for (int i = 0; i < (int)elements.size(); i++) {
    string my_print = "";
    for (int j = 0; j < elements[i].size(); j++) {
      my_print += check_digit(elements[i][j]);
    }
    cout << my_print << endl;
  }

  return 0;
}
