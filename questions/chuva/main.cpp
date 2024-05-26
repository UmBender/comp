#include <bits/stdc++.h>
#include <climits>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int bsup(vector<int> &values, int target) {
  int down = 0;
  int up = values.size() - 1;
  int middle = (down + up) / 2;
  while (!(values[middle] == target &&
           (middle == values.size() - 1 || values[middle + 1] != target)) &&
         up != down) {
    if (values[middle] < target) {
      if (down == middle) {
        down += 1;
      } else {
        down = middle;
      }
    } else {

      up = middle;
    }
    middle = (down + up) / 2;
  }
  if (values[middle] != target) {
    return -1;
  }
  return middle;
}
int bsdown(vector<int> &values, int target) {
  int down = 0;
  int up = values.size() - 1;
  int middle = (down + up) / 2;
  int lastup = INT_MAX;
  int lastdown = -1;

  while (!(values[middle] == target && (values[middle - 1] < target)) &&
         up != down) {
    lastup = up;
    lastdown = down;

    if (values[middle] >= target) {
      up = middle;
    } else {
      down = middle;
    }
    if (lastup == up && lastdown == down) {
      middle = down;
      break;
    }

    middle = (up + down) / 2;
  }

  if (values[middle] != target && values[middle + 1] != target) {
    return -1;
  }

	if(values[middle] == target) {
		return middle;
	}
  if (values[middle + 1] == target) {
    return middle + 1;
  }
  return middle;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> x(n);
  for (auto &i : x) {
    cin >> i;
  }

  vector<int> sum(n + 1, 0);
  sum[0] = 0;
  for (int i = 1; i < sum.size(); i++) {
    sum[i] = sum[i - 1] + x[i - 1];
  }
  int counter = 0;
  for (int i = 0; i < sum.size(); i++) {
    int value = sum[i];
    int target = value + s;
		int upp = bsup(sum,target);
		int downn = bsdown(sum,target);
		if(upp == -1 || downn == -1) {
			continue;
		}else{
			counter += 1 + upp -downn;
		}
  }
	cout << counter << endl;


  return 0;
}
