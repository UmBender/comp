#include <bits/stdc++.h>
#include <cmath>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

struct Max {
  int init;
  int end;
};

vector<int> convert(string &i) {
  vector<int> arr(i.size());
  for (int k = 0; k < i.size(); k++) {
    if (i[k] == '0') {
      arr[k] = 0;
    } else {
      arr[k] = 1;
    }
  }
  return arr;
}

/*Max find(vector<int> &val) {
  int first_zero = -1;
  for (int i = 0; i < val.size(); i++) {
    if (val[i] == 0) {
                        first_zero = i;
    }
  }
}

*/
void teste(vector<int> &val) {
  int state = val[0];
  int counter = 1;
	bool got_middle = false;
	bool almost = false;
  for (int i = 0; i < val.size(); i++) {
		if(val[i] == 0) {
			almost = true;;
		}
		if(val[i] == 1 && almost) {
			got_middle = true;
		}
		if(state != val[i]) {
			state = val[i];
			counter++;
		}
  }
	if(got_middle) {
		counter--;
	}
	cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  vector<string> arr(t);
  for (auto &i : arr) {
    cin >> i;
  }
  for (auto &i : arr) {
    vector<int> ele = convert(i);
    teste(ele);
  }

  return 0;
}
