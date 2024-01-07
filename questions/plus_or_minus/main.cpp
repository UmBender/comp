#include <bits/stdc++.h>


using namespace std;
struct Elem {
	int a;
	int b;
	int c;

};

int main(int argc, char** argv)
{
	int t  = 0;
	cin >> t;
	Elem array[t];

	for(int i = 0; i < t; i++) {
		cin >> array[i].a >> array[i].b >> array[i].c;
	}

	for(int i = 0; i < t; i++) {
		cout << (((array[i].a + array[i].b) == array[i].c) ? "+":"-" )<< endl;

	}
	



	return 0;
}
