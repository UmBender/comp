#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

mt19937 rng(random_device{}());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> k(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> k[i][j];
		}
	}

	auto rotate = [&]() {
		auto temp = k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				k[i][j] = temp[j][n - 1 - i];
			}
		}
	};
	auto check = [&]() -> bool {
		bool okay = true;

		for (int i = 0; i < n && okay; i++) {
			for (int j = 0; j < n - 1 && okay; j++) {
				if (k[i][j] > k[i][j + 1]) {
					okay = false;
				}
			}
		}
		for (int i = 0; i < n - 1 && okay; i++) {
			for (int j = 0; j < n && okay; j++) {
				if (k[i][j] > k[i + 1][j]) {
					okay = false;
				}
			}
		}

		return okay;
	};

	int counter = 0;
	while (!check()){
		rotate();
		counter++;
	}
	cout << counter << endl;
	return 0;

	


}
