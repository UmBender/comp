#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n, l;
  cin >> n >> l;
	int a[n];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a,a+n);
	int max_diff = 2*max(a[0], l-a[n-1]);
	for(int i = 0; i < n-1;i++) {
		max_diff = max(max_diff, a[i+1] - a[i]);
	}

	

  printf("%.10f\n", max_diff / 2.);

  return 0;
}
