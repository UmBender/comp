#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;
#define int ll

int32_t main() {
  int t, s, h;
  cin >> t >> s >> h;

  for (int i = 0; i < t; i++) {
		cout << "*";
    for (int j = 0; j < s ; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < s ; j++) {
			cout << " ";
		}	
		cout << "*";

    cout << endl;
  }

  for (int i = 0; i < s * 2 + 3; i++) {
    cout << "*";
  }

  cout << endl;
	for (int i = 0; i < h; i++) {

    for (int j = 0; j < s+1 ; j++) {
			cout << " ";
		}
		cout << "*";


    cout << endl;
  }


  return 0;
}
