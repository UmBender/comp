#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n, k;
	cin >> n >> k;
	int x[n];
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	queue<int> numbers;
	map<int, int> counter;
	int acc = 0;
	for (int i = 0; i < n; i++) {
		numbers.push(x[i]);
		counter[x[i]]++;
		while (counter.size() > k) {
			int tail = numbers.front();
			numbers.pop();
			counter[tail]--;
			if (counter[tail] == 0) { counter.erase(tail); }
		}
		acc += numbers.size();
	}
	cout << acc << endl;
}
