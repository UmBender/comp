#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Obj{
	int n;
	int d;
	vector<int> elem;
};

int main(int argc, char** argv)
{
	int t = 0;
	cin >> t;

	Obj list[t];
	for(int i = 0; i < t; i++) {
		cin >> list[i].n >> list[i].d;
		for(int j = 0; j < list[i].n; j++) {
			int new_elem =0;
			cin >> new_elem;
			list[i].elem.push_back(new_elem);

		}
		sort(list[i].elem.begin(), list[i].elem.end());
	}
	for(int i = 0; i < t; i++) {
		if(list[i].elem[list[i].n - 1] <= list[i].d || list[i].elem[0]+list[i].elem[1] <= list[i].d) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}

	}




	return 0;
}
