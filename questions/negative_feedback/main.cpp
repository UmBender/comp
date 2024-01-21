#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

using dd = long double;
#define double dd

int32_t main() {
  int vin, rf, rg;
  cin >> vin >> rf >> rg;
	double result = (double) vin + vin * ((double)rf / (double) rg);
	cout << result;	

  return 0;
}
