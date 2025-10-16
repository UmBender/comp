#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int left = -1, right = -1, sum = 0, counter = 0;
	while (right < n - 1) {
		if (sum <= x) {
			right++;
			sum += a[right];
			if (sum == x) { counter++; }
		} else {
			left++;
			sum -= a[left];
			if (sum == x) { counter++; }
		}
	}
	while (left < n - 1) {
		left++;
		sum -= a[left];
		if (sum == x) { counter++; }
	}
	cout << counter << endl;
}
