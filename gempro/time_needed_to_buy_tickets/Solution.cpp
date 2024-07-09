#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int counter = 0;
    int max_rep = tickets[k];
    for (int j = 0; j < (int)tickets.size(); j++) {
      int i = tickets[j];
      if (j <= k) {
        if (i > max_rep) {
          counter += max_rep;
        } else {
          counter += i;
        }
      } else {
        if (i >= max_rep) {
          counter += max_rep - 1;
        } else {
          counter += i;
        }
      }
    }

    return counter;
  }
};
