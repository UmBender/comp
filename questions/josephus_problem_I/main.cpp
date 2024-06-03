#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	queue<int> josephus;
	
	for(int i = 1; i<=n;i++) {
		josephus.push(i);
	}

	while (josephus.size() >1) {
		int a,b;
		a = josephus.front();
		josephus.pop();
		b = josephus.front();
		josephus.pop();
		cout << b << " ";
		josephus.push(a);
	}
	cout << josephus.front() << endl;

  return 0;
}
