#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int t = 0;
	cin >> t;
	int elements[t];
	for(int i =0; i < t; i++) {

		cin >> elements[i];
	}
	
	for(int i  = 0; i< t; i++) {

		cout << elements[i]/2 + elements[i]%2 << endl;
	}









	return 0;
}
