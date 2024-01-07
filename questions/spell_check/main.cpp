#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

using ll = long long;
#define int ll

struct Obj {
	string word;
	int size;
};

int32_t main()
{
	int carac[256];
	memset(carac, 0,sizeof(int) *  256);
	int dope[256];
	memset(dope, 0,sizeof(int) *  256);

	char cops[] = "Timur";
	for(int i = 0; i < 5; i++) {
		carac[(uint64_t)cops[i]]++;
	}

	int t = 0;
	cin >> t;
	Obj lista[t];
	for(int i = 0; i < t; i++) {
		cin >> lista[i].size;
		cin >> lista[i].word;
	}

	for(int i = 0; i < t; i++) {
		bool wirt = true;
		if(lista[i].size != 5) {
			cout << "NO" << endl;
			continue;
		}
		for(int j = 0 ;j <lista[i].size; j++) {
			dope[(int)lista[i].word[j]]++;
		}
		for(int j = 0; j < 256; j++) {
			if(carac[j] != dope[j]) {
				cout << "NO" << endl;
				wirt = false;
				break;
			}
		}
		if(wirt) {
			cout << "YES" << endl;
		}
		memset(dope, 0, sizeof(int) * 256);

	}




  return 0;
}
