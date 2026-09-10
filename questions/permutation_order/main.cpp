#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int comb(int n, int k) {
	int acc = 1;
	for (int i = k + 1; i <= n; i++)  {
		acc *= i;
	}
	for (int i = 2; i <= n - k; i++) {
		acc /= i;
	}

	return acc;
}

int fact(int n) {
	int acc = 1;
	for (int i = 2; i <= n; i++) {
		acc *= i;
	}
	return acc;
}



void solution();
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}

void first();
void second();

void solution() {
	int opt;
	cin >> opt;
	if (opt == 1) {
		first();
	} else {
		second();
	}
}

void first() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	vector<int> notUsed(n);
	iota(begin(notUsed), end(notUsed), 1ll);
	k--;
	for (int i = 0; i < n; i++) {
		int actualFact = fact(n - (i + 1));
		int j = 0;
		while (actualFact <= k) {
			j++;
			k -= actualFact;
		}
		p[i] = notUsed[j];
		notUsed.erase(begin(notUsed) + j);
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

void second() {
	int n;
	cin >> n;

	int acc = 1;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	vector<int> notUsed(n);
	iota(begin(notUsed), end(notUsed), 1ll);
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(begin(notUsed), end(notUsed), p[i]) - begin(notUsed);
		int quant = fact(n - (i + 1));
		acc += quant * pos;
		notUsed.erase(begin(notUsed) + pos);
	}
	cout << acc << endl;
}
