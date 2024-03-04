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
    int n, k;
    cin >> n >> k;
    int number_b = k / 2;
    int rest_a = n % k;
		if(n%k > number_b) {

			cout << n - rest_a+ number_b << endl;
		}else {
			cout << n  << endl;
		}

    t--;
  }

  return 0;
}
