#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void teste(int a, int b, int c, int d) {
	int countc = -1;
	int countd = -1;
	int i = a+1;
  while(i != b) {
		if(i == c) {
			countc = 1;
		}
		if(i == d) {
			countd = 1;
		}
		i ++;
		if(i > 12) {
			i= 1;
		}
  }
	if(countc == 1 && countd == -1) {
		cout << "YES" << endl;
		return;
	}
	if(countc == -1 && countd == 1) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  int arr[t][4];
  for (int i = 0; i < t; i++) {
    int a, b, c, d;
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
  }
  for (int i = 0; i < t; i++) {
    teste(arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }

  return 0;
}
