#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;

#define int ll

constexpr int MAXN = 1e12 + 1e10;

vector<int> three;
inline int calc(int i) {
	return (i + 1) * i / 2;
}

void setup() {
	int i = 2;
	three.reserve(2e6);
	three.push_back(0);
	three.push_back(1);
	for (int j = 3; j < MAXN; j += i) {
		i++;
		three.push_back(j);
	}
}

bool one(int n) {
	auto it = lower_bound(begin(three), end(three), n);
	return *it == n;
}


bool two(int n) {
	int l = 0, r = lower_bound(begin(three), end(three), n) - begin(three);
	while (l <= r) {
		int sum = three[l] + three[r];
		if (sum == n) return true;
		if (sum < n) l ++;
		if (sum > n) r--;
	}
	return false;
}



int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (one(n)) {
			cout << 1 << endl;
			continue;
		} else if (two(n)) {
			cout << 2 << endl;
			continue;
		} 
		cout << 3 << endl;
	}
	return 0;
}
