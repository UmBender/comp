#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

bool is_vowel(char letra) {
  switch (letra) {

  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
		return true;
	default:
		return false;
  }
}
bool is_voweln(char letra) {
  switch (letra) {

  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'n':
		return true;
	default:
		return false;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string word;
  cin >> word;
  for (int i = 0; i < word.length(); i++) {
		if(is_voweln(word[i])) {
			continue;

		}else{
			if(i+1 == word.length()){
				cout << "NO" << endl;
				return 0;
			}
			if(!is_vowel(word[i+1])) {
				cout << "NO" << endl;
				return 0;

			}

		}


	}
	cout << "YES" << endl;

  return 0;
}
