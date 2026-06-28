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
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	for (int i = 0; i < h; i++) {
		cin >> c[i];
	}
	int top = 0;
	int bottom = h - 1;
	int left = 0;
	int right = w - 1;
	auto checkTop = [&]() -> bool {
		for (int i = left; i <= right; i++) {
			if (c[top][i] == '#') {
				return false;
			}
		}
		return true;
	};
	auto checkBot = [&]() -> bool {
		for (int i = left; i <= right; i++) {
			if (c[bottom][i] == '#') {
				return false;
			}
		}
		return true;
	};
	auto checkLeft = [&]() -> bool {
		for (int i = top; i <= bottom; i++) {
			if (c[i][left] == '#') {
				return false;
			}
		}
		return true;
	};
	auto checkRight = [&]() -> bool {
		for (int i = top; i <= bottom; i++) {
			if (c[i][right] == '#') {
				return false;
			}
		}
		return true;
	};
	while(checkTop() && top < bottom) {
		top++;
	}
	while(checkBot() && bottom > top) {
		bottom--;
	}
	while(checkLeft() && left < right) {
		left++;
	}
	while(checkRight() && right > left) {
		right--;
	}	
	for (int i = top; i <= bottom; i++) {
		for(int j = left; j <= right; j ++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	
	
    return 0;
}
