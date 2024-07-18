#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {}

int dfs(int value, int target) {
  if (value == target) {
    return target;
  }
  if (target == 0 || target == 1) {
    return target;
  }
	int divisor = 10;
	if(target % divisor == 0) {
		target = target / divisor;
	}else{
		divisor = next_divisor(divisor);
	}
	do {
		while(target % divisor !=0 &&divisor * divisor <= target) {

		}

	}while(divisor * divisor <= target);


}
	int next_divisor(int value) {

}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solution();
  }
  return 0;
}
