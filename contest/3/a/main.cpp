#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution(string &word) {
	int suma = 0, sumb =0;
	for(int i =0; i< 6;i++) {
		if(i < 3) {
			suma+= (word[i] - '0');
		}else{
			sumb+= (word[i] - '0');
		}
	}
	if(sumb == suma) {
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string word;
    cin >> word;
    solution(word);
  }

  return 0;
}
