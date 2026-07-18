#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solution();
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}

void solution() {
	ll px, py, qx, qy, rx, ry, sx, sy;
	cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
	ll v1x = qx - px;
	ll v1y = qy - py;
	ll v2x = sx - rx;
	ll v2y = sy - ry;

	ll cross = v1x * v2y - v1y * v2x;
	if (cross != 0) {
		cout << "Yes" << endl;
		return;
	} else {
		ll vmidx = (rx + sx) - (px + qx);
		ll vmidy = (ry + sy) - (py + qy);

		ll dot = vmidx * v1x + vmidy * v1y;
		if (dot == 0) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}
