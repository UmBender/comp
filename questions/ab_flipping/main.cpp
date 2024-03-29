#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    string caps;
    cin >> n >> caps;
    int counter = 0;
		int last_moved = 1000000000000000000;
		int wow = 100000000000000000;
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i; j < n && caps[j] == 'A' && caps[j + 1] == 'B' && j < wow; j++) {
				if(last_moved > j) {
					last_moved = j;
				}
        caps[j] = 'B';
        caps[j + 1] = 'A';
        counter++;
      }
			wow = last_moved;
    }
		cout << counter << '\n';
		t--;
  }

  return 0;
}
